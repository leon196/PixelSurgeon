PIXI.SimpleFilter = function()
{
    PIXI.AbstractFilter.call( this );

    this.passes = [this];

    // set the uniforms
    this.uniforms = {
        uFrame: {type: '2fv', value:new PIXI.Float32Array([1.0, 1.0])}
        , uPixelSize: {type: '1f', value: 64.0 }
    };

    this.fragmentSrc = [
        'precision mediump float;',
        'varying vec2 vTextureCoord;',
        'varying vec4 vColor;',
        'uniform vec2 uFrame;',
        'uniform float uPixelSize;',
        'uniform sampler2D uSampler;',

        // Dat random function for glsl
        'float rand(vec2 co){ return fract(sin(dot(co.xy, vec2(12.9898,78.233))) * 43758.5453); }',

        // Pixelize coordinates
        'vec2 pixelize(vec2 uv, vec2 details) { return floor(uv * details) / details; }',

        'void main(void) {',
        '   vec2 uv = vTextureCoord;',
        '   float ratio = uFrame.y / uFrame.x;',
        '   uv = pixelize(uv, vec2(uPixelSize, uPixelSize * ratio));',
        '   vec4 color = texture2D(uSampler, uv);',
        '   gl_FragColor = color;',
        '}'
    ];
};

PIXI.SimpleFilter.prototype = Object.create( PIXI.AbstractFilter.prototype );
PIXI.SimpleFilter.prototype.constructor = PIXI.SimpleFilter;

// Frame
Object.defineProperty(PIXI.SimpleFilter.prototype, 'frame', {
    get: function() { return this.uniforms.uFrame.value; },
    set: function(value) { this.dirty = true; this.uniforms.uFrame.value = value; }
});

// Pixel Size
Object.defineProperty(PIXI.SimpleFilter.prototype, 'pixelSize', {
    get: function() { return this.uniforms.uPixelSize.value; },
    set: function(value) { this.dirty = true; this.uniforms.uPixelSize.value = value; }
});