
// Engine
var Engine = {};
Engine.frame = { 
	width: window.innerWidth, 
	height: window.innerHeight,
	min: Math.min(window.innerWidth, window.innerHeight),
	middle: { x: window.innerWidth / 2, y: window.innerHeight / 2 } };

// PIXI setup
Engine.stage = new PIXI.Stage(0x000000);
Engine.renderer = PIXI.autoDetectRenderer(
	Engine.frame.width, 
	Engine.frame.height);

// Add PIXI to <div>
Engine.div = document.getElementById("canvas");
Engine.div.appendChild(Engine.renderer.view);

// Layers setup
Engine.layer = new PIXI.DisplayObjectContainer();
Engine.stage.addChild(Engine.layer);
Engine.addToStage = function(sprite) { 
	Engine.layer.addChild(sprite) 
};

// Drawer setup
Drawer.Setup();
  
// Mouse Events (Desktop & Mobile)
Engine.stage.mousedown = Engine.stage.touchstart = onMouseDown;
Engine.stage.mouseup = Engine.stage.mouseupoutside = onMouseUp;
Engine.stage.touchend = Engine.stage.touchendoutside = onMouseUp;
Engine.stage.mousemove = Engine.stage.touchmove = onMouseMove;

// Game Logic
Engine.tick = 0;
Engine.mouse = { x: 0, y: 0 };
Engine.mouseBefore = { x: 0, y: 0 };

// PIXI Loader
// var loader = new PIXI.AssetLoader(["img/test.png"]);
// loader.onComplete = function() {};
// loader.load();

// Game Loop
Engine.Update = function() {

	// Update logic
	++Engine.tick;

	// Update drawing
	Drawer.Update();

    // PIXI render
    Engine.renderer.render( Engine.stage );

	// Request next update
    requestAnimFrame( Engine.Update );
}

requestAnimFrame( Engine.Update );

function onMouseDown (data) {
	data.originalEvent.preventDefault();
	Engine.mouse = getCroppedPosition(getRelativePosition(data.global));
    // Drawer.isDrawing = true;
}

function onMouseUp (data) {
	Engine.mouse = getCroppedPosition(getRelativePosition(data.global));
	// Drawer.isDrawing = false;
}

function onMouseMove (data) {
	Engine.mouse = getCroppedPosition(getRelativePosition(data.global));
}

function getRelativePosition(p) {
	return { 
		x: Math.floor((p.x / Engine.frame.width) * Drawer.frame.width), 
		y: Math.floor((p.y / Engine.frame.height) * Drawer.frame.height) };
}

function getCroppedPosition(p) {
	return { 
		x: Math.max(0, Math.min(Drawer.frame.width, p.x)), 
		y: Math.max(0, Math.min(Drawer.frame.height, p.y)) };
}