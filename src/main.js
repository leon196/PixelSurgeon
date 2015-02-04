
var stage = new PIXI.Stage(0x000000);
var frame = { width: window.innerWidth, height: window.innerHeight };
var renderer = PIXI.autoDetectRenderer(frame.width, frame.height);
var canvas = document.getElementById("canvas");
canvas.appendChild(renderer.view);

var drawer = new PIXI.Graphics();
var drawerFrame = { width: 128, height: 128 };
var renderTexture = new PIXI.RenderTexture(drawerFrame.width, drawerFrame.height, null, PIXI.scaleModes.NEAREST);
var filter = new PIXI.SimpleFilter();
filter.frame[0] = frame.width;
filter.frame[1] = frame.height;
filter.pixelSize = 512;
var layer = new PIXI.DisplayObjectContainer();
// layer.filters = [filter];
stage.addChild(layer);

var tick = 0, oscillation;
var mouse = { x: 0, y: 0 };
var mouseBefore = { x: 0, y: 0 };
var drawing = false;
var image;

var loader = new PIXI.AssetLoader(["img/test.png"]);
loader.onComplete = function() {

	image = new PIXI.Sprite(renderTexture);
	image.width = frame.height;
	image.height = frame.height;
	image.x = (frame.width - image.width) / 2;
	layer.addChild(image);

	// Mouse Events
	stage.mousedown = stage.touchstart = onMouseDown;
	stage.mouseup = stage.mouseupoutside = stage.touchend = stage.touchendoutside = onMouseUp;
	stage.mousemove = stage.touchmove = onMouseMove;

    requestAnimFrame( animate );
};
loader.load();


// Game Loop
function animate() 
{
	++tick;

    oscillation = Math.cos(tick * 0.1) * 0.5 + 0.5;
	filter.pixelSize = Math.pow(2, Math.floor(oscillation * 4) + 6);

    requestAnimFrame( animate );
    renderer.render(stage);
}

function onMouseDown (data) {
	data.originalEvent.preventDefault();
	var localPosition = data.getLocalPosition(image);
	mouse.x = localPosition.x;
	mouse.y = localPosition.y;
    drawing = true;
}

function onMouseUp (data) {
	drawing = false;
}

function onMouseMove (data) {
	if(drawing) {
		var localPosition = data.getLocalPosition(image);
		mouseBefore.x = mouse.x;
		mouseBefore.y = mouse.y;

		mouse.x = localPosition.x;
		mouse.y = localPosition.y;

		// var mBefore = getRelativePosition(mouseBefore);
		// var m = getRelativePosition(mouse);
		var mBefore = getCroppedPosition(mouseBefore);
		var m = getCroppedPosition(mouse);

	// fadeOut();

		drawer.lineStyle(1, Color.Rainbow());
		// drawer.drawRect(m.x, m.y, 4, 4);
		drawer.moveTo(drawerFrame.width / 2, drawerFrame.height / 2);
		drawer.lineTo(m.x, m.y);

		renderTexture.render(drawer);
	}
}

function fadeOut() {
	drawer.beginFill(0x000000, 0.01);
	drawer.drawRect(0, 0, drawerFrame.width, drawerFrame.height);
	renderTexture.render(drawer);
}

function getRelativePosition(p)
{
	return { x: Math.floor((p.x / frame.width) * drawerFrame.width), y: Math.floor((p.y / frame.height) * drawerFrame.height) };
}

function getCroppedPosition(p)
{
	return { x: Math.max(0, Math.min(frame.width, p.x)), y: Math.max(0, Math.min(frame.height, p.y)) };
}