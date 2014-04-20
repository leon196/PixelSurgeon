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
	
	private var dimension:Int = 128;
	private var pixelSize:Float = 8.0;
	private var image:Bitmap;
	private var background:Bitmap;
	private var pixels:BitmapData;
	private var pixelsBuffer:BitmapData;
	private var pixelsBackground:BitmapData;
	private var timeLast:Int;
	private var timer:Timer;
	private var fps:FPS;
	private var debug:TextField;

	private var velocityX:Float = 0.0;
	private var velocityY:Float = 0.0;
	private var movingUp:Bool = false;
	private var movingDown:Bool = false;
	private var movingLeft:Bool = false;
	private var movingRight:Bool = false;
	private var mouseClic:Bool = false;

	static inline private var MAX_SPEED:Float = 200.0;

	static inline private var colorRed = 0xffa64c4c;
	static inline private var colorGreen = 0xffa6dc4c;
	static inline private var colorBlue = 0xff4c97dc;
	static inline private var colorYellow = 0xffffc515;
	static inline private var colorWhite = 0xffffffff;
	static inline private var colorAlive = 0xFFCCCCCC;
	static inline private var colorDead = 0x00000000;
	
	public function new () {
		
		super ();
		
		background = new Bitmap (Assets.getBitmapData ("assets/map.png"));
		addChild(background);
		//background.x = background.y = 0.0;
		background.scaleX = background.scaleY = pixelSize;

		pixels = new BitmapData(dimension, dimension, true, colorDead);
		pixelsBuffer = new BitmapData(dimension, dimension, true, colorDead);
		image = new Bitmap(pixels, PixelSnapping.NEVER, false);
		addChild(image);

		pixelsBackground = background.bitmapData;
		
		image.x = image.y = 0.0;
		image.scaleX = image.scaleY = pixelSize;

		for ( i in 0...dimension*dimension) {
			var color = Math.random() > 0.9 ? colorAlive : colorDead;
			pixels.setPixel32((i + Math.floor(i/dimension)) % dimension, Math.floor(i/dimension), color);
			pixelsBuffer.setPixel32((i + Math.floor(i/dimension)) % dimension, Math.floor(i/dimension), color);
		}

		timer = new Timer (500);
        timer.addEventListener(TimerEvent.TIMER, onTimer);
        timer.start();

        debug = new TextField();
        debug.autoSize = TextFieldAutoSize.LEFT;
        var format:TextFormat = new TextFormat();
        format.font = "Verdana";
        format.color = 0xff0000;
        format.size = 10;
        debug.defaultTextFormat = format;
        //addChild(debug);

        fps = new FPS(10, 10, 0xff0000);
        addChild(fps);

        timeLast = Lib.getTimer();
		addEventListener(Event.ENTER_FRAME, onEnterFrame);

		stage.addEventListener(KeyboardEvent.KEY_DOWN, onKeyDown);
		stage.addEventListener(KeyboardEvent.KEY_UP, onKeyUp);

		image.addEventListener(MouseEvent.MOUSE_DOWN, onMouseDown);
		image.addEventListener(MouseEvent.MOUSE_UP, onMouseUp);
	}

	private function onTimer(event:TimerEvent):Void {
		pixels.lock();
		pixelsBuffer = pixels.clone();
		for ( i in 0...dimension*dimension) {
			var x = i % dimension;
			var y = Math.floor(i / dimension); 
			var pixelColor:String = StringTools.hex(pixels.getPixel32(x, y));
			var backgroundColor:String = StringTools.hex(pixelsBackground.getPixel32(x, y));
			var countAround:Int = howManyAround(x, y, colorAlive);

			// Zone check
			if (backgroundColor == StringTools.hex(colorGreen)) {

				// translation

				if (StringTools.hex(pixelsBuffer.getPixel32(x, y)) == StringTools.hex(colorAlive)) {
					pixels.setPixel32(x, y, colorDead);
					pixels.setPixel32(x + 1, y, colorAlive);
				}

			} else if (backgroundColor == StringTools.hex(colorWhite)) {

				// game of life

				// current is alive
				if (pixelColor == StringTools.hex(colorAlive)) {
					// die
					if (countAround != 2 && countAround != 3) {
						pixels.setPixel32(x, y, colorDead);	
					}
				} 
				// current is dead
				else {
					if (countAround == 3) {
						pixels.setPixel32(x, y, colorAlive);
					}
				}
			}
		}
		pixelsBuffer = pixels.clone();
		pixels.unlock();
	}

	private function onKeyDown(event:KeyboardEvent):Void {
		switch (event.keyCode) {
			case Keyboard.W: movingUp = true;
			case Keyboard.S: movingDown = true;
			case Keyboard.A: movingLeft = true;
			case Keyboard.D: movingRight = true;
		}
	}

	private function onKeyUp(event:KeyboardEvent):Void {
		switch (event.keyCode) {
			case Keyboard.W: movingUp = false;
			case Keyboard.S: movingDown = false;
			case Keyboard.A: movingLeft = false;
			case Keyboard.D: movingRight = false;
		}
	}

	private function onMouseDown(event:MouseEvent):Void {
		mouseClic = true;
	}

	private function onMouseUp(event:MouseEvent):Void {
		mouseClic = false;
	}

	private var accelerator:Float = 2.0;
	private var deccelerator:Float = 0.9;
	private function onEnterFrame(event:Event):Void {

		//debug.text = "mouse X : " + image.mouseX + " mouse Y : " + image.mouseY;

		if (mouseClic) {
			pixels.setPixel32(Math.floor(image.mouseX), Math.floor(image.mouseY), 0xffcccccc);
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
			if (velocityY <= -0.001 && velocityY >= 0.001) {
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
			if (velocityX <= -0.001 && velocityX >= 0.001) {
				velocityX = velocityX * deccelerator;
			} else {
				velocityX = 0.0;
			}
		}

		var delta = (Lib.getTimer() - timeLast) / 1000.0;
		image.x -= velocityX * delta;
		image.y -= velocityY * delta;
		background.x = image.x;
		background.y = image.y;
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

	private function testPosition(x:Int, y:Int):Bool {
		return (x >= 0 && x < dimension && y >= 0 && y < dimension);
	}
	
	
}