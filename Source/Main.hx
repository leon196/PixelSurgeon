package;


import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Sprite;
import flash.display.PixelSnapping;
import flash.text.TextField;
import flash.text.TextFieldAutoSize;
import flash.text.TextFormat;
import flash.events.Event;
import flash.events.TimerEvent;
import flash.events.KeyboardEvent;
import flash.events.MouseEvent;
import flash.utils.Timer;
import flash.Lib;
import flash.ui.Keyboard;
import openfl.Assets;
import openfl.display.FPS;
import StringTools;
import Std;


class Main extends Sprite {
	
	private var scene:Sprite;
	private var dimension:Int = 128;
	private var pixelSize:Float = 10.0;
	private var image:Bitmap;
	private var background:Bitmap;
	private var pixels:BitmapData;
	private var pixelsBuffer:BitmapData;
	private var pixelsBackground:BitmapData;
	private var timeLast:Int;
	private var timer:Timer;
	private var fps:FPS;
	private var debug:TextField;
	private var debugCellsCount:Array<TextField> = new Array<TextField>();
	private var cellsCount:Array<Int> = new Array<Int>();
	private var colors:Array<Int> = new Array<Int>();

	private var velocityX:Float = 0.0;
	private var velocityY:Float = 0.0;
	private var movingUp:Bool = false;
	private var movingDown:Bool = false;
	private var movingLeft:Bool = false;
	private var movingRight:Bool = false;
	private var mouseClic:Bool = false;
	
	private var pickingColor:Bool = true;
	private var brushColor:UInt = 0x00000000;

	static inline private var MAX_SPEED:Float = 200.0;
	
	static inline private var colorWhite = 0xffffffff;
	static inline private var colorRed = 0xffA64C4C;
	static inline private var colorRedDark = 0xffA6344C;
	static inline private var colorGreen = 0xffA6DC4C;
	static inline private var colorBlue = 0xff4C97DC;
	static inline private var colorYellow = 0xffFFC515;
	static inline private var colorPurple = 0xffd559cb;
	static inline private var colorBlueDark = 0xff5961d5;
	static inline private var colorPurpleDark = 0xff7e3578;
	static inline private var colorOrange = 0xffff7d15;
	static inline private var colorGreenDark = 0xff527d15;
	
	static inline private var colorAlive = 0x77000000;
	static inline private var colorDead = 0x00000000;
	
	public function new () {
		
		super ();
		
		scene = new Sprite();
		addChild(scene);
		
		background = new Bitmap (Assets.getBitmapData ("assets/map.png"));
		scene.addChild(background);
		background.scaleX = background.scaleY = pixelSize;
		
		pixels = new BitmapData(dimension, dimension, true, colorDead);
		pixelsBuffer = new BitmapData(dimension, dimension, true, colorDead);
		image = new Bitmap(pixels, PixelSnapping.NEVER, false);
		scene.addChild(image);
		
		pixelsBackground = background.bitmapData;
		
		image.x = image.y = background.x = background.y = 0.0;
		image.scaleX = image.scaleY = pixelSize;
		
		var agents:Bitmap = new Bitmap(Assets.getBitmapData("assets/map_agents.png"));
		var pixelAgents:BitmapData = agents.bitmapData;
		
		colors = new Array();
		
		// explore image pixels
		for ( i in 0...dimension * dimension) {
			
			var x = i % dimension;
			var y = Math.floor(i / dimension);
			// set random alive cells
			//var color = Math.random() > 0.9 ? colorAlive : colorDead;
			var color = pixelAgents.getPixel32(x, y);
			pixels.setPixel32(x, y, color);
			pixelsBuffer.setPixel32(x, y, color);
			
			// found a new color
			color = pixelsBackground.getPixel(x, y);
			var index = colors.indexOf(color);
			var tfColor:TextField;
			if (index == -1) {
				colors.push(color);
				tfColor = new TextField();
				var textFormat:TextFormat = new TextFormat("Arial", 20, color, true);
				tfColor.defaultTextFormat = textFormat;
				tfColor.text = "cell count";
				tfColor.x = x * pixelSize;// 10;
				tfColor.y = y * pixelSize;// 50 + colors.length * 30;
				//tfColor.scaleX = tfColor.scaleY = 1 / pixelSize;
				var textBackground:Sprite = new Sprite();
				var g = textBackground.graphics;
				g.beginFill(0xffffff, 0.5);
				g.drawRect(tfColor.x, tfColor.y, tfColor.text.length * 5.5, 20);
				g.endFill();
				scene.addChild(textBackground);
				scene.addChild(tfColor);
				debugCellsCount.push(tfColor);
				cellsCount.push(1);
			} else {
				cellsCount[index]++;
				//tfColor = debugCellsCount[index];
				//tfColor.x += x;// * pixelSize;
				//tfColor.y += y;// * pixelSize;
			}
			
			var cellCount = cellsCount.length;
			for ( i in 0...cellCount) {
				tfColor = debugCellsCount[i];
				tfColor.text = "" + cellsCount[i];
			}
		}
		
		timer = new Timer (200);
		timer.addEventListener(TimerEvent.TIMER, onTimer);
		timer.start();
		
		debug = new TextField();
		debug.x = debug.y = 10;
		debug.autoSize = TextFieldAutoSize.LEFT;
		var format:TextFormat = new TextFormat();
		format.font = "Arial";
		format.color = 0x333333;
		format.size = 16;
		debug.defaultTextFormat = format;
		debug.text = "WASD or ZQSD to Move /  Numpad + - to Change Speed / Clic from color to draw color / Colors represent different rules of cellular automaton";
		addChild(debug);
		
		fps = new FPS(10, 30, 0x333333);
		addChild(fps);
		
		timeLast = Lib.getTimer();
		addEventListener(Event.ENTER_FRAME, onEnterFrame);
		
		stage.addEventListener(KeyboardEvent.KEY_DOWN, onKeyDown);
		stage.addEventListener(KeyboardEvent.KEY_UP, onKeyUp);
		
		stage.addEventListener(MouseEvent.MOUSE_DOWN, onMouseDown);
		stage.addEventListener(MouseEvent.MOUSE_UP, onMouseUp);
	}
	
	private function cellCountAdd(indexColor:UInt) {
		if (indexColor != -1) {
			cellsCount[indexColor]++;
		}
	}
	
	private function applyRule(agents:BitmapData, background:BitmapData, x:Int, y:Int, birth:Array<Int>, survive:Array<Int>, newColor:UInt) {
		var colorAgent:String = StringTools.hex(agents.getPixel32(x, y));
		var indexColor:Int = colors.indexOf(pixelsBackground.getPixel(x, y));
		var countAround:Int = howManyAroundNotAndIn(x, y, colorDead, pixelsBackground.getPixel32(x, y));
		// Births
		if (colorAgent == StringTools.hex(colorDead)) {
			for (i in 0...birth.length) {
				if (birth[i] == countAround) {
					agents.setPixel32(x, y, newColor);
					cellCountAdd(indexColor);
					break;
				}
			}
		} 
		// Survive
		else {
			var willSurvive:Bool = false;
			for (i in 0...survive.length) {
				if (survive[i] == countAround) {
					willSurvive = true;
					cellCountAdd(indexColor);
					break;
				}
			} if (willSurvive == false) {
				agents.setPixel32(x, y, colorDead);
			}
		}
	}

	private function onTimer(event:TimerEvent):Void {
		for ( i in 0...colors.length ) {
			cellsCount[i] = 0;
		}
		pixels.lock();
		pixelsBuffer = pixels.clone();
		for ( i in 0...dimension*dimension) {
			var x = i % dimension;
			var y = Math.floor(i / dimension); 
			var pixelColor:String = StringTools.hex(pixels.getPixel32(x, y));
			var backgroundColor:String = StringTools.hex(pixelsBackground.getPixel32(x, y));
			var countAround:Int = howManyAroundNot(x, y, colorDead);
			
			// Zone check
			
			// green 
			if (backgroundColor == StringTools.hex(colorGreen)) {
				
				if (StringTools.hex(pixelsBuffer.getPixel32(x, y)) != StringTools.hex(colorDead)) {
					
					pixels.setPixel32(x, y, colorDead);
					
					if ((StringTools.hex(pixelsBackground.getPixel32(x, y-1)) == StringTools.hex(colorGreen)
					|| StringTools.hex(pixelsBackground.getPixel32(x - 1, y - 1)) == StringTools.hex(colorGreenDark))
					&& StringTools.hex(pixels.getPixel32(x, y-1)) == StringTools.hex(colorDead))
					{
						pixels.setPixel32(x, y-1, colorAlive);
					}
					else if ((StringTools.hex(pixelsBackground.getPixel32(x+1, y-1)) == StringTools.hex(colorGreen)
					|| StringTools.hex(pixelsBackground.getPixel32(x - 1, y - 1)) == StringTools.hex(colorGreenDark))
					&& StringTools.hex(pixels.getPixel32(x+1, y-1)) == StringTools.hex(colorDead))
					{
						pixels.setPixel32(x+1, y-1, colorAlive);
					}
					else if ((StringTools.hex(pixelsBackground.getPixel32(x - 1, y - 1)) == StringTools.hex(colorGreen)
					|| StringTools.hex(pixelsBackground.getPixel32(x - 1, y - 1)) == StringTools.hex(colorGreenDark))
					&& StringTools.hex(pixels.getPixel32(x-1, y-1)) == StringTools.hex(colorDead))
					{
						pixels.setPixel32(x-1, y-1, colorAlive);
					}
					else
					{
						pixels.setPixel32(x, y, colorAlive);
					}
				}
				
			}
			else if (backgroundColor == StringTools.hex(colorRedDark)) {
				
				if (StringTools.hex(pixelsBuffer.getPixel32(x, y)) != StringTools.hex(colorDead)) {
					
					pixels.setPixel32(x, y, colorDead);
					
					if (StringTools.hex(pixelsBackground.getPixel32(x, y+1)) == StringTools.hex(colorRedDark)
					&& StringTools.hex(pixels.getPixel32(x, y+1)) == StringTools.hex(colorDead))
					{
						pixels.setPixel32(x, y+1, colorAlive);
					}
					else if (StringTools.hex(pixelsBackground.getPixel32(x+1, y+1)) == StringTools.hex(colorRedDark)
					&& StringTools.hex(pixels.getPixel32(x+1, y+1)) == StringTools.hex(colorDead))
					{
						pixels.setPixel32(x+1, y+1, colorAlive);
					}
					else if (StringTools.hex(pixelsBackground.getPixel32(x-1, y+1)) == StringTools.hex(colorRedDark)
					&& StringTools.hex(pixels.getPixel32(x-1, y+1)) == StringTools.hex(colorDead))
					{
						pixels.setPixel32(x-1, y+1, colorAlive);
					}
					else
					{
						pixels.setPixel32(x, y, colorAlive);
					}
				}
			}
			// B1357 / S1357
			else if (backgroundColor == StringTools.hex(colorRed))
			{
				applyRule(pixels, pixelsBackground, x, y, [1, 3, 5, 7], [1, 3, 5, 7], colorAlive);
			}
			// B25 / S4
			else if (backgroundColor == StringTools.hex(colorBlue))
			{
				applyRule(pixels, pixelsBackground, x, y, [2, 5], [4], colorAlive);
			}
			// B3 / S012345678
			else if (backgroundColor == StringTools.hex(colorYellow))
			{
				applyRule(pixels, pixelsBackground, x, y, [3], [0, 1, 2, 3, 4, 5, 6, 7, 8], colorAlive);
			} 
			// B34 / S34
			else if (backgroundColor == StringTools.hex(colorPurple))
			{
				applyRule(pixels, pixelsBackground, x, y, [3, 4], [3, 4], colorAlive);
			}
			// B35678 / S5678
			else if (backgroundColor == StringTools.hex(colorBlueDark))
			{
				applyRule(pixels, pixelsBackground, x, y, [3, 5, 6, 7, 8], [5, 6, 7, 8], colorAlive);
			}
			// B36 / S125
			else if (backgroundColor == StringTools.hex(colorPurpleDark)) 
			{
				applyRule(pixels, pixelsBackground, x, y, [3, 6], [1, 2, 5], colorAlive);
			}
			// B3678 / S34678
			else if (backgroundColor == StringTools.hex(colorOrange))
			{
				applyRule(pixels, pixelsBackground, x, y, [3, 6, 7, 8], [3, 4, 6, 7, 8], colorAlive);
			}
			// B368 / S245
			else if (backgroundColor == StringTools.hex(colorGreenDark))
			{
				//applyRule(pixels, pixelsBackground, x, y, [3, 6, 8], [2, 4, 5], colorAlive);
				applyRule(pixels, pixelsBackground, x, y, [1, 2, 3, 4, 5, 6, 7, 8], [0, 1, 2, 3, 4, 5, 6, 7, 8], colorAlive);
			} 
			// B3 / S23 (Conway Game of Life)
			else if (backgroundColor == StringTools.hex(colorWhite)) 
			{
				//applyRule(pixels, pixelsBackground, x, y, [3], [2, 3], colorAlive);
				pixels.setPixel32(x, y, colorDead);
			}
		}
		pixelsBuffer = pixels.clone();
		pixels.unlock();
		
		for ( i in 0...cellsCount.length) {
			var tfColor = debugCellsCount[i];
			tfColor.text = "" + cellsCount[i];
		}
	}

	private function onKeyDown(event:KeyboardEvent):Void {
		switch (event.keyCode) {
			case Keyboard.W: movingUp = true;
			case Keyboard.Z: movingUp = true;
			case Keyboard.S: movingDown = true;
			case Keyboard.A: movingLeft = true;
			case Keyboard.Q: movingLeft = true;
			case Keyboard.D: movingRight = true;
			case Keyboard.SPACE: pickingColor = true;
			case Keyboard.NUMPAD_ADD: speedUp();
			case Keyboard.NUMPAD_SUBTRACT: speedDown();
		}
	}

	private function onKeyUp(event:KeyboardEvent):Void {
		switch (event.keyCode) {
			case Keyboard.W: movingUp = false;
			case Keyboard.Z: movingUp = false;
			case Keyboard.S: movingDown = false;
			case Keyboard.A: movingLeft = false;
			case Keyboard.Q: movingLeft = false;
			case Keyboard.D: movingRight = false;
			case Keyboard.SPACE: pickingColor = false;
		}
	}

	private function onMouseDown(event:MouseEvent):Void {
		mouseClic = true;
	}

	private function onMouseUp(event:MouseEvent):Void {
		mouseClic = false;
		pickingColor = true;
	}

	private var accelerator:Float = 1.5;
	private var deccelerator:Float = 0.95;
	private function onEnterFrame(event:Event):Void {

		//debug.text = "mouse X : " + image.mouseX + " mouse Y : " + image.mouseY;

		if (mouseClic) {
			var x = Math.floor(background.mouseX);
			var y = Math.floor(background.mouseY);
			if (pickingColor) {
				brushColor = pixelsBackground.getPixel32(x, y);
				pickingColor = false;
			}
			//else {
				pixelsBackground.setPixel32(x, y, brushColor);
				pixelsBackground.setPixel32(x, y-1, brushColor);
				pixelsBackground.setPixel32(x-1, y, brushColor);
				pixelsBackground.setPixel32(x, y+1, brushColor);
				pixelsBackground.setPixel32(x+1, y, brushColor);
			//}
		}

		//image.x = 100.0 + Math.cos(Lib.getTimer() * 0.001) * 20.0;
		//image.y = 100.0 + Math.sin(Lib.getTimer() * 0.001) * 20.0;
		//image.scaleX = image.scaleY = 10.0 + (Math.cos(Lib.getTimer() * 0.001) + 1.0) * 0.5;
		if (movingUp) {
			if (velocityY >= 0.0) { velocityY = -1.0; }
			velocityY = Math.max(-MAX_SPEED, velocityY * accelerator);
		} else if (movingDown) {
			if (velocityY <= 0.0) { velocityY = 1.0; }
			velocityY = Math.min(MAX_SPEED, velocityY * accelerator);
		} else {
			if (velocityY <= -0.01 || velocityY >= 0.01) {
				velocityY = velocityY * deccelerator;
			} else {
				velocityY = 0.0;
			}
		}
		if (movingLeft) {
			if (velocityX >= 0.0) { velocityX = -1; }
			velocityX = Math.max(-MAX_SPEED, velocityX * accelerator);
		} else if (movingRight) {
			if (velocityX <= 0.0) { velocityX = 1; }
			velocityX = Math.min(MAX_SPEED, velocityX * accelerator);
		} else {
			if (velocityX <= -0.01 || velocityX >= 0.01) {
				velocityX = velocityX * deccelerator;
			} else {
				velocityX = 0.0;
			}
		}

		var delta = (Lib.getTimer() - timeLast) / 1000.0;
		scene.x -= velocityX * delta;
		scene.y -= velocityY * delta;
		timeLast = Lib.getTimer();
	}

	private function howManyAround(x:Int, y:Int, target:UInt):Int {
		var count:Int = 0;
		if (testPosition(x, y)) {
			for (row in -1...2) {
				for (col in -1...2) {
					if (testPosition(x + row, y + col)) {
						if ((row == 0 && col == 0) == false)  {
							if (StringTools.hex(pixelsBuffer.getPixel32(x + row, y + col)) == StringTools.hex(target)) {
								count++;
							}
						}
					}
				}
			}
			return count;
		} else {
			return -1;
		}
	}

	private function howManyAroundNot(x:Int, y:Int, target:UInt):Int {
		var count:Int = 0;
		if (testPosition(x, y)) {
			for (row in -1...2) {
				for (col in -1...2) {
					if (testPosition(x + row, y + col)) {
						if ((row == 0 && col == 0) == false)  {
							if (StringTools.hex(pixelsBuffer.getPixel32(x + row, y + col)) != StringTools.hex(target)) {
								count++;
							}
						}
					}
				}
			}
			return count;
		} else {
			return -1;
		}
	}

	private function howManyAroundNotAndIn(x:Int, y:Int, target:UInt, colorEnvironment:UInt):Int {
		var count:Int = 0;
		if (testPosition(x, y)) {
			for (row in -1...2) {
				for (col in -1...2) {
					if (testPosition(x + row, y + col)) {
						if ((row == 0 && col == 0) == false)  {
							if (StringTools.hex(pixelsBuffer.getPixel32(x + row, y + col)) != StringTools.hex(target)
							&& StringTools.hex(pixelsBackground.getPixel32(x + row, y + col)) == StringTools.hex(colorEnvironment)) {
								count++;
							}
						}
					}
				}
			}
			return count;
		} else {
			return -1;
		}
	}
	
	private function zoom():Void {
		pixelSize = Math.max(1.0, Math.min(pixelSize + 1.0, 40.0));
		image.scaleX = image.scaleY = pixelSize;
		background.scaleX = background.scaleY = pixelSize;
	}
	
	private function unZoom():Void {
		pixelSize = Math.max(1.0, Math.min(pixelSize - 1.0, 40.0));
		image.scaleX = image.scaleY = pixelSize;
		background.scaleX = background.scaleY = pixelSize;
	}
	
	private function speedUp():Void {
		timer.delay = Math.max(10.0, Math.min(timer.delay * 0.5, 1000.0));
	}
	
	private function speedDown():Void {
		timer.delay = Math.max(10.0, Math.min(timer.delay * 2.0, 1000.0));
	}

	private function testPosition(x:Int, y:Int):Bool {
		return (x >= 0 && x < dimension && y >= 0 && y < dimension);
	}
	
	
}