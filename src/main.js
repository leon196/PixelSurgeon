
var stage = new PIXI.Stage(0x000000);
var frame = { width: window.innerWidth, height: window.innerHeight };
var renderer = PIXI.autoDetectRenderer(frame.width, frame.height);
var canvas = document.getElementById("canvas");
canvas.appendChild(renderer.view);

var drawer = new PIXI.Graphics();
var drawerFrame = { width: 128, height: 128 };
var renderTexture = new PIXI.RenderTexture(drawerFrame.width, drawerFrame.height);
var filter = new PIXI.SimpleFilter();
filter.frame[0] = frame.width;
filter.frame[1] = frame.height;
filter.pixelSize = 512;
var layer = new PIXI.DisplayObjectContainer();
// layer.filters = [filter];
stage.addChild(layer);

var tick = 0;
var mouse = { x: 0, y: 0 };
var mouseBefore = { x: 0, y: 0 };
var image;

var loader = new PIXI.AssetLoader(["img/test.png"]);
loader.onComplete = function() {

	image = new PIXI.Sprite(renderTexture);
	image.width = frame.height;
	image.height = frame.height;
	image.x = (frame.width - image.width) / 2;
	layer.addChild(image);

	// Mouse Events
	canvas.addEventListener('mousemove', onMouseMove);
	// canvas.addEventListener('mousedown', onMouseDown);
	// canvas.addEventListener('mouseup', onMouseUp);

    requestAnimFrame( animate );
};
loader.load();


// Game Loop
function animate() {

	++tick;

    requestAnimFrame( animate );

    var ocsillation = Math.cos(tick * 0.1) * 0.5 + 0.5;
	// image.scale.x = image.scale.y = 1 + ocsillation * 1;
	filter.pixelSize = Math.pow(2, Math.floor(ocsillation * 4) + 6);




    // render the stage  
    renderer.render(stage);
}

function onMouseMove(e)
{
	mouseBefore.x = mouse.x;
	mouseBefore.y = mouse.y;

	mouse.x = e.pageX;
	mouse.y = e.pageY;

	var mBefore = getRelativePosition(mouseBefore);
	var m = getRelativePosition(mouse);

	drawer.lineStyle(2, 0xff0000);
	drawer.moveTo(mBefore.x, mBefore.y);
	drawer.lineTo(m.x, m.y);
	renderTexture.render(drawer);
}

function getRelativePosition(p)
{
	return { x: Math.floor((p.x / frame.width) * drawerFrame.width), y: Math.floor((p.y / frame.height) * drawerFrame.height) };
}