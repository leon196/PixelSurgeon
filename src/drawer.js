var Drawer = {};

Drawer.Setup = function() {

	var w = Utils.NearestPow2(Engine.frame.width / Parameter.globalScale);
	var h = Utils.NearestPow2(Engine.frame.height / Parameter.globalScale);
	Drawer.frame = { 
		width: w, 
		height: h,
		middle: { x: w / 2, y: h / 2} };

	Drawer.isDrawing = false;

	// Create canvas 2d context
	// Drawer.bufferCanvas = document.createElement("canvas");
	// Drawer.bufferContext = bufferCanvas.getContext('2d');

	// Useful for drawing with PIXI
	Drawer.graphics = new PIXI.Graphics();

	// Render texture steup
	Drawer.renderTexture = new PIXI.RenderTexture(
		Drawer.frame.width, 
		Drawer.frame.height, 
		null, PIXI.scaleModes.NEAREST);

	// Image setup
	Drawer.renderImage = new PIXI.Sprite(Drawer.renderTexture);
	Drawer.renderImage.width = Engine.frame.width;
	Drawer.renderImage.height = Engine.frame.height;
	Drawer.renderImage.anchor.x = 0.5;
	Drawer.renderImage.anchor.y = 0.5;
	Drawer.renderImage.x = Engine.frame.width / 2;
	Drawer.renderImage.y = Engine.frame.height / 2;

	// Add sprite to stage
	Engine.addToStage(Drawer.renderImage);

}

// var curveSegmentCount = Drawer.frame.width / 8;
// var lineCount = Drawer.frame.height / 16;
// var timeSpeed = 2;
// var perlinScaleX = 0.05;
// var perlinScaleY = 0.01;
// var frequenceX = 20;
// var frequenceY = 8;
// var x = 0;
// var perlin;
// var y;
// var previous = { x: 0, y: 0 };

Drawer.Render = function() {
	Drawer.renderTexture.render(Drawer.graphics);
}

Drawer.Line = function(thickness, color, from, to) {
	Drawer.graphics.lineStyle(thickness, color);
	Drawer.graphics.moveTo(from.x, from.y);
	Drawer.graphics.lineTo(to.x, to.y);
}

Drawer.Update = function() {

	if (Parameter.clearAuto) {
		Drawer.graphics.clear();
		Drawer.renderTexture.clear();
	}
	
	if (Parameter.drawing) {
		Drawer.Line(1, Color.Rainbow(), Drawer.frame.middle, Engine.mouse);
		Drawer.Render();
	}

	// for (var ligne = 0; ligne < lineCount; ++ligne) {
	// 	y = ligne * (4 + perlin * 0.5 + 0.5) * (4 + (Math.costick * 0.1) * 0.5 + 0.5);
	// 	drawer.moveTo(0, y);
	// 	previous.x = 0;
	// 	previous.y = y;

	// 	for (var i = 0; i <= curveSegmentCount; ++i) {
	// 		perlinY = noise({x: ((ligne + i) * frequenceY + tick * timeSpeed) * perlinScaleY, y: 0, z: (i * frequenceX + tick * timeSpeed) * perlinScaleY});
	// 		x = (i / curveSegmentCount) * drawerFrame.width;
	// 		y = ligne * 8 * (1 + (perlinY * 0.5 + 0.5));
	// 		var dotdot = Utils.dot(Utils.Normalize({x: x - previous.x, y: y - previous.y}), {x : 0, y: 1});
	// 		dotdot = Math.abs(dotdot);
	// 		drawer.lineStyle(1, Color.GetRainbow(dotdot));
	// 		drawer.lineTo(x, drawerFrame.height - y);
	// 		previous.x = x;
	// 		previous.y = y;
	// 	}
	// }
	Drawer.Render();
}

	// var from = mouse;
	// var to = { 
	// 	x: halfWidth + Math.cos(tick * frequenceX) * halfWidth, 
	// 	y: halfHeight + Math.sin(tick * frequenceY) * halfHeight };
	// var count = drawerFrame.width;
	// for (var i = 0; i < count; ++i) {
 //    	oscillation = Math.cos(tick * 0.001 + i) * 0.5 + 0.5;
	// 	var frequenceX = 0.001;// + oscillation * 0.02;
	// 	var frequenceY = 0.2;
	// 	var sinY = Math.sin((tick + i) * frequenceY);
	// 	var x = (i / count) * drawerFrame.width * 3 - drawerFrame.width;
	// 	var h = halfHeight / 4;
	// 	var y = drawerFrame.height - h;
	// 	var perlinScale = 64;
	// 	var perlin = noise({x: (x + tick * 4) / perlinScale, y: 0, z: 0});
	// 	drawLine(4, Color.Gray(1 - (perlin * 0.5 + 0.5)), from, { 
	// 		x: x, y: y - perlin * h });
	// }
	// count *= 2;
	// for (var i = 0; i < count; ++i) {
 //    	oscillation = Math.cos(tick * 0.001 + i) * 0.5 + 0.5;
	// 	var frequenceX = 0.001;// + oscillation * 0.02;
	// 	var frequenceY = 0.2;
	// 	var sinY = Math.sin((tick + i) * frequenceY);
	// 	var x = (i / count) * drawerFrame.width;
	// 	var h = halfHeight / 4;
	// 	var perlinScale = 8;
	// 	var perlin = noise({x: (x + tick * 0.5) / perlinScale, y: 0, z: 0});
	// 	var perlin2 = noise({x: (x + tick * 1) / 12, y: 0, z: 0});
	// 	drawLine(4, Color.GetRainbow(1 - (perlin * 0.5 + 0.5)), from, { 
	// 		x: x + perlin2 * 16, y: h - perlin * h });
	// }



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