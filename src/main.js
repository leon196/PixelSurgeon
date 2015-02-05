
var stage = new PIXI.Stage(0x000000);
var frame = { width: window.innerWidth, height: window.innerHeight };
var renderer = PIXI.autoDetectRenderer(frame.width, frame.height);
var canvas = document.getElementById("canvas");
canvas.appendChild(renderer.view);

var bufferCanvas = document.createElement("canvas");
var bufferContext = bufferCanvas.getContext('2d');

var drawer = new PIXI.Graphics();
var drawerFrame = { width: Utils.NearestPow2(frame.width / 16), height: Utils.NearestPow2(frame.height / 16) };
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
var drawerScale = 2;
var image;

var loader = new PIXI.AssetLoader(["img/test.png"]);
loader.onComplete = function() {

	image = new PIXI.Sprite(renderTexture);
	image.width = frame.width;
	image.height = frame.height;
	image.anchor.x = 0.5;
	image.anchor.y = 0.5;
	image.x = frame.width / 2;
	image.y = frame.height / 2;
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

    oscillation = Math.cos(tick * 0.01) * 0.5 + 0.5;
	filter.pixelSize = Math.pow(2, Math.floor(oscillation * 4) + 6);

	// drawer.lineStyle(0);
	// drawer.beginFill(0x000000, 0.05);
	// drawer.drawRect(0, 0, drawerFrame.width, drawerFrame.height);
	drawer.clear();
	renderTexture.clear();

	var halfWidth = drawerFrame.width / 2;
	var halfHeight = drawerFrame.height / 2;
	var from = mouse;
	// var to = { 
	// 	x: halfWidth + Math.cos(tick * frequenceX) * halfWidth, 
	// 	y: halfHeight + Math.sin(tick * frequenceY) * halfHeight };
	var count = drawerFrame.width;
	for (var i = 0; i < count; ++i) {
    	oscillation = Math.cos(tick * 0.001 + i) * 0.5 + 0.5;
		var frequenceX = 0.001;// + oscillation * 0.02;
		var frequenceY = 0.2;
		drawLine(2, Color.Get(tick + i), from, { 
			x: (i / count) * drawerFrame.width, 
			y: drawerFrame.height / 8 + Math.sin((tick + i) * frequenceY) * halfHeight / 4
		});
	}
	for (var i = 0; i < count; ++i) {
    	oscillation = Math.cos(tick * 0.001 + i) * 0.5 + 0.5;
		var frequenceX = 0.001;// + oscillation * 0.02;
		var frequenceY = 0.2;
		var sinY = Math.sin((tick + i) * frequenceY);
		drawLine(2, Color.Gray(sinY * 0.5 + 0.5), from, { 
			x: (i / count) * drawerFrame.width, 
			y: drawerFrame.height - drawerFrame.height / 8 + sinY * halfHeight / 4
		});
	}

	renderTexture.render(drawer);

    requestAnimFrame( animate );
    renderer.render(stage);
}

function onMouseDown (data) {
	data.originalEvent.preventDefault();

	mouse = getCroppedPosition(getRelativePosition(data.global));

	// bufferContext.drawImage(renderTexture.getImage(), 0, 0, drawerFrame.width, drawerFrame.height);
	// var imageData = bufferContext.getImageData(0, 0, drawerFrame.width, drawerFrame.height);
	// var count = (drawerFrame.width * drawerFrame.height) * 4 - 4;
	// for (var i = 0; i < count; i += 4) {
	// 	var r = imageData.data[i];
	// 	var g = imageData.data[i+1];
	// 	var b = imageData.data[i+2];
	// 	var a = imageData.data[i+3];
	// 	var lum = (r + g + b) / (3.0 * 255.0);
	// 	var x = Math.floor(i / 4) % drawerFrame.width;
	// 	var y = Math.floor( Math.floor(i / 4) / drawerFrame.width );
	// 	if (lum > 0.75) {
	// 		drawer.lineStyle(0);
	// 		drawer.beginFill(0xff0000);
	// 		drawer.drawRect(x, y, 1, 1);
	// 		drawer.endFill();
	// 	}
	// }

	// renderTexture.render(drawer);

    drawing = true;
}

function onMouseUp (data) {
	drawing = false;
		mouse = getCroppedPosition(getRelativePosition(data.global));

}

function onMouseMove (data) {
		mouse = getCroppedPosition(getRelativePosition(data.global));
	if (drawing) {

		var from = { x: drawerFrame.width / 2, y: drawerFrame.height / 2 };
		var to = { x: mouse.x, y: mouse.y };
		drawLine(1, Color.Rainbow(), from, to);


		renderTexture.render(drawer);
	}
}

function drawLine (thickness, color, from, to) {
	drawer.lineStyle(thickness, color);
	drawer.moveTo(from.x, from.y);
	drawer.lineTo(to.x, to.y);
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
	return { x: Math.max(0, Math.min(drawerFrame.width, p.x)), y: Math.max(0, Math.min(drawerFrame.height, p.y)) };
}