#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash_display_Bitmap
#include <flash/display/Bitmap.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_Graphics
#include <flash/display/Graphics.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_PixelSnapping
#include <flash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_display_Stage
#include <flash/display/Stage.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_KeyboardEvent
#include <flash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_flash_events_MouseEvent
#include <flash/events/MouseEvent.h>
#endif
#ifndef INCLUDED_flash_events_TimerEvent
#include <flash/events/TimerEvent.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_flash_text_TextFieldAutoSize
#include <flash/text/TextFieldAutoSize.h>
#endif
#ifndef INCLUDED_flash_text_TextFormat
#include <flash/text/TextFormat.h>
#endif
#ifndef INCLUDED_flash_ui_Keyboard
#include <flash/ui/Keyboard.h>
#endif
#ifndef INCLUDED_flash_utils_ByteArray
#include <flash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_flash_utils_IDataInput
#include <flash/utils/IDataInput.h>
#endif
#ifndef INCLUDED_flash_utils_IDataOutput
#include <flash/utils/IDataOutput.h>
#endif
#ifndef INCLUDED_flash_utils_Timer
#include <flash/utils/Timer.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
#ifndef INCLUDED_openfl_display_FPS
#include <openfl/display/FPS.h>
#endif
#ifndef INCLUDED_openfl_utils_IMemoryRange
#include <openfl/utils/IMemoryRange.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_FRAME("Main","new",0x6616a5cb,"Main.new","Main.hx",26,0x087e5c05)
{
	HX_STACK_LINE(321)
	this->deccelerator = 0.95;
	HX_STACK_LINE(320)
	this->accelerator = 1.5;
	HX_STACK_LINE(53)
	this->brushColor = (int)0;
	HX_STACK_LINE(52)
	this->pickingColor = true;
	HX_STACK_LINE(50)
	this->mouseClic = false;
	HX_STACK_LINE(49)
	this->movingRight = false;
	HX_STACK_LINE(48)
	this->movingLeft = false;
	HX_STACK_LINE(47)
	this->movingDown = false;
	HX_STACK_LINE(46)
	this->movingUp = false;
	HX_STACK_LINE(45)
	this->velocityY = 0.0;
	HX_STACK_LINE(44)
	this->velocityX = 0.0;
	HX_STACK_LINE(42)
	this->colors = Array_obj< int >::__new();
	HX_STACK_LINE(41)
	this->cellsCount = Array_obj< int >::__new();
	HX_STACK_LINE(40)
	this->debugCellsCount = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(30)
	this->pixelSize = 10.0;
	HX_STACK_LINE(29)
	this->dimension = (int)128;
	HX_STACK_LINE(74)
	super::__construct();
	HX_STACK_LINE(76)
	this->scene = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(77)
	this->addChild(this->scene);
	HX_STACK_LINE(79)
	this->background = ::flash::display::Bitmap_obj::__new(::openfl::Assets_obj::getBitmapData(HX_CSTRING("assets/map.png"),null()),null(),null());
	HX_STACK_LINE(80)
	this->scene->addChild(this->background);
	HX_STACK_LINE(81)
	this->background->set_scaleX(this->background->set_scaleY(this->pixelSize));
	HX_STACK_LINE(83)
	this->pixels = ::flash::display::BitmapData_obj::__new(this->dimension,this->dimension,true,(int)0,null());
	HX_STACK_LINE(84)
	this->pixelsBuffer = ::flash::display::BitmapData_obj::__new(this->dimension,this->dimension,true,(int)0,null());
	HX_STACK_LINE(85)
	this->image = ::flash::display::Bitmap_obj::__new(this->pixels,::flash::display::PixelSnapping_obj::NEVER,false);
	HX_STACK_LINE(86)
	this->scene->addChild(this->image);
	HX_STACK_LINE(88)
	this->pixelsBackground = this->background->bitmapData;
	HX_STACK_LINE(90)
	this->image->set_x(this->image->set_y(this->background->set_x(this->background->set_y(0.0))));
	HX_STACK_LINE(91)
	this->image->set_scaleX(this->image->set_scaleY(this->pixelSize));
	HX_STACK_LINE(93)
	::flash::display::Bitmap agents = ::flash::display::Bitmap_obj::__new(::openfl::Assets_obj::getBitmapData(HX_CSTRING("assets/map_agents.png"),null()),null(),null());		HX_STACK_VAR(agents,"agents");
	HX_STACK_LINE(94)
	::flash::display::BitmapData pixelAgents = agents->bitmapData;		HX_STACK_VAR(pixelAgents,"pixelAgents");
	HX_STACK_LINE(96)
	this->colors = Array_obj< int >::__new();
	HX_STACK_LINE(99)
	{
		HX_STACK_LINE(99)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(99)
		int _g = (this->dimension * this->dimension);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(99)
		while(((_g1 < _g))){
			HX_STACK_LINE(99)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(101)
			int x = hx::Mod(i,this->dimension);		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(102)
			int y = ::Math_obj::floor((Float(i) / Float(this->dimension)));		HX_STACK_VAR(y,"y");
			HX_STACK_LINE(105)
			int color = pixelAgents->getPixel32(x,y);		HX_STACK_VAR(color,"color");
			HX_STACK_LINE(106)
			this->pixels->setPixel32(x,y,color);
			HX_STACK_LINE(107)
			this->pixelsBuffer->setPixel32(x,y,color);
			HX_STACK_LINE(110)
			color = this->pixelsBackground->getPixel(x,y);
			HX_STACK_LINE(111)
			int index = this->colors->indexOf(color,null());		HX_STACK_VAR(index,"index");
			HX_STACK_LINE(112)
			::flash::text::TextField tfColor;		HX_STACK_VAR(tfColor,"tfColor");
			HX_STACK_LINE(113)
			if (((index == (int)-1))){
				HX_STACK_LINE(114)
				this->colors->push(color);
				HX_STACK_LINE(115)
				tfColor = ::flash::text::TextField_obj::__new();
				HX_STACK_LINE(116)
				::flash::text::TextFormat textFormat = ::flash::text::TextFormat_obj::__new(HX_CSTRING("Arial"),(int)20,color,true,null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(textFormat,"textFormat");
				HX_STACK_LINE(117)
				tfColor->set_defaultTextFormat(textFormat);
				HX_STACK_LINE(118)
				tfColor->set_text(HX_CSTRING("cell count"));
				HX_STACK_LINE(119)
				tfColor->set_x((x * this->pixelSize));
				HX_STACK_LINE(120)
				tfColor->set_y((y * this->pixelSize));
				HX_STACK_LINE(122)
				::flash::display::Sprite textBackground = ::flash::display::Sprite_obj::__new();		HX_STACK_VAR(textBackground,"textBackground");
				HX_STACK_LINE(123)
				::flash::display::Graphics g = textBackground->get_graphics();		HX_STACK_VAR(g,"g");
				HX_STACK_LINE(124)
				g->beginFill((int)16777215,0.5);
				HX_STACK_LINE(125)
				Float _g2 = tfColor->get_x();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(125)
				Float _g11 = tfColor->get_y();		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(125)
				g->drawRect(_g2,_g11,(tfColor->get_text().length * 5.5),(int)20);
				HX_STACK_LINE(126)
				g->endFill();
				HX_STACK_LINE(129)
				this->debugCellsCount->push(tfColor);
				HX_STACK_LINE(130)
				this->cellsCount->push((int)1);
			}
			else{
				HX_STACK_LINE(132)
				(this->cellsCount[index])++;
			}
			HX_STACK_LINE(138)
			int cellCount = this->cellsCount->length;		HX_STACK_VAR(cellCount,"cellCount");
			HX_STACK_LINE(139)
			{
				HX_STACK_LINE(139)
				int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(139)
				while(((_g2 < cellCount))){
					HX_STACK_LINE(139)
					int i1 = (_g2)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(140)
					tfColor = this->debugCellsCount->__get(i1).StaticCast< ::flash::text::TextField >();
					HX_STACK_LINE(141)
					tfColor->set_text((HX_CSTRING("") + this->cellsCount->__get(i1)));
				}
			}
		}
	}
	HX_STACK_LINE(145)
	this->timer = ::flash::utils::Timer_obj::__new((int)200,null());
	HX_STACK_LINE(146)
	this->timer->addEventListener(::flash::events::TimerEvent_obj::TIMER,this->onTimer_dyn(),null(),null(),null());
	HX_STACK_LINE(147)
	this->timer->start();
	HX_STACK_LINE(149)
	this->debug = ::flash::text::TextField_obj::__new();
	HX_STACK_LINE(150)
	this->debug->set_x(this->debug->set_y((int)10));
	HX_STACK_LINE(151)
	this->debug->set_autoSize(::flash::text::TextFieldAutoSize_obj::LEFT);
	HX_STACK_LINE(152)
	::flash::text::TextFormat format = ::flash::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(format,"format");
	HX_STACK_LINE(153)
	format->font = HX_CSTRING("Arial");
	HX_STACK_LINE(154)
	format->color = (int)3355443;
	HX_STACK_LINE(155)
	format->size = (int)16;
	HX_STACK_LINE(156)
	this->debug->set_defaultTextFormat(format);
	HX_STACK_LINE(157)
	this->debug->set_text(HX_CSTRING("WASD or ZQSD to Move /  Numpad + - to Change Speed / Clic from color to draw color / Colors represent different rules of cellular automaton"));
	HX_STACK_LINE(158)
	this->addChild(this->debug);
	HX_STACK_LINE(160)
	this->fps = ::openfl::display::FPS_obj::__new((int)10,(int)30,(int)3355443);
	HX_STACK_LINE(161)
	this->addChild(this->fps);
	HX_STACK_LINE(163)
	this->timeLast = ::flash::Lib_obj::getTimer();
	HX_STACK_LINE(164)
	this->addEventListener(::flash::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
	HX_STACK_LINE(166)
	this->get_stage()->addEventListener(::flash::events::KeyboardEvent_obj::KEY_DOWN,this->onKeyDown_dyn(),null(),null(),null());
	HX_STACK_LINE(167)
	this->get_stage()->addEventListener(::flash::events::KeyboardEvent_obj::KEY_UP,this->onKeyUp_dyn(),null(),null(),null());
	HX_STACK_LINE(169)
	this->get_stage()->addEventListener(::flash::events::MouseEvent_obj::MOUSE_DOWN,this->onMouseDown_dyn(),null(),null(),null());
	HX_STACK_LINE(170)
	this->get_stage()->addEventListener(::flash::events::MouseEvent_obj::MOUSE_UP,this->onMouseUp_dyn(),null(),null(),null());
}
;
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::cellCountAdd( int indexColor){
{
		HX_STACK_FRAME("Main","cellCountAdd",0xf39b0589,"Main.cellCountAdd","Main.hx",174,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(indexColor,"indexColor")
		struct _Function_1_1{
			inline static Float Block( int &indexColor){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",174,0x087e5c05)
				{
					HX_STACK_LINE(174)
					int _int = indexColor;		HX_STACK_VAR(_int,"int");
					HX_STACK_LINE(174)
					return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(174)
		if (((_Function_1_1::Block(indexColor) != (int)-1))){
			HX_STACK_LINE(175)
			(this->cellsCount[indexColor])++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,cellCountAdd,(void))

Void Main_obj::applyRule( int x,int y,Array< int > birth,Array< int > survive,int newColor){
{
		HX_STACK_FRAME("Main","applyRule",0x160bb135,"Main.applyRule","Main.hx",179,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(birth,"birth")
		HX_STACK_ARG(survive,"survive")
		HX_STACK_ARG(newColor,"newColor")
		HX_STACK_LINE(180)
		::String colorAgent = ::StringTools_obj::hex(this->pixelsBuffer->getPixel32(x,y),null());		HX_STACK_VAR(colorAgent,"colorAgent");
		HX_STACK_LINE(181)
		int indexColor = this->colors->indexOf(this->pixelsBackground->getPixel(x,y),null());		HX_STACK_VAR(indexColor,"indexColor");
		HX_STACK_LINE(182)
		int countAround = this->howManyAroundNot(x,y,(int)0);		HX_STACK_VAR(countAround,"countAround");
		HX_STACK_LINE(184)
		if (((colorAgent == ::StringTools_obj::hex((int)0,null())))){
			HX_STACK_LINE(185)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(185)
			int _g = birth->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(185)
			while(((_g1 < _g))){
				HX_STACK_LINE(185)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(186)
				if (((birth->__get(i) == countAround))){
					HX_STACK_LINE(187)
					this->pixels->setPixel32(x,y,newColor);
					HX_STACK_LINE(188)
					this->cellCountAdd(indexColor);
					HX_STACK_LINE(189)
					break;
				}
			}
		}
		else{
			HX_STACK_LINE(195)
			bool willSurvive = false;		HX_STACK_VAR(willSurvive,"willSurvive");
			HX_STACK_LINE(196)
			{
				HX_STACK_LINE(196)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(196)
				int _g = survive->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(196)
				while(((_g1 < _g))){
					HX_STACK_LINE(196)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(197)
					if (((survive->__get(i) == countAround))){
						HX_STACK_LINE(198)
						willSurvive = true;
						HX_STACK_LINE(199)
						this->cellCountAdd(indexColor);
						HX_STACK_LINE(200)
						break;
					}
				}
			}
			HX_STACK_LINE(202)
			if (((willSurvive == false))){
				HX_STACK_LINE(203)
				this->pixels->setPixel32(x,y,(int)0);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Main_obj,applyRule,(void))

Void Main_obj::moveFromTo( int fromX,int fromY,int offsetX,int offsetY,int newColor){
{
		HX_STACK_FRAME("Main","moveFromTo",0x9d7c956b,"Main.moveFromTo","Main.hx",209,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(fromX,"fromX")
		HX_STACK_ARG(fromY,"fromY")
		HX_STACK_ARG(offsetX,"offsetX")
		HX_STACK_ARG(offsetY,"offsetY")
		HX_STACK_ARG(newColor,"newColor")
		HX_STACK_LINE(210)
		this->pixels->setPixel32(fromX,fromY,(int)0);
		HX_STACK_LINE(211)
		this->pixels->setPixel32((fromX + offsetX),(fromY + offsetY),newColor);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Main_obj,moveFromTo,(void))

int Main_obj::colorLighter( int color){
	HX_STACK_FRAME("Main","colorLighter",0x6a14e8d5,"Main.colorLighter","Main.hx",217,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_ARG(color,"color")
	HX_STACK_LINE(217)
	return (int((((int(color) >> int((int)24))) - (int)8)) << int((int)24));
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,colorLighter,return )

Void Main_obj::onTimer( ::flash::events::TimerEvent event){
{
		HX_STACK_FRAME("Main","onTimer",0x0aa4c511,"Main.onTimer","Main.hx",220,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(224)
		this->pixels->lock();
		HX_STACK_LINE(225)
		this->pixelsBuffer = this->pixels->clone();
		HX_STACK_LINE(226)
		{
			HX_STACK_LINE(226)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(226)
			int _g = (this->dimension * this->dimension);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(226)
			while(((_g1 < _g))){
				HX_STACK_LINE(226)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(227)
				int x = hx::Mod(i,this->dimension);		HX_STACK_VAR(x,"x");
				HX_STACK_LINE(228)
				int y = ::Math_obj::floor((Float(i) / Float(this->dimension)));		HX_STACK_VAR(y,"y");
				HX_STACK_LINE(229)
				::String pixelColor = ::StringTools_obj::hex(this->pixels->getPixel32(x,y),null());		HX_STACK_VAR(pixelColor,"pixelColor");
				HX_STACK_LINE(230)
				::String backgroundColor = ::StringTools_obj::hex(this->pixelsBackground->getPixel32(x,y),null());		HX_STACK_VAR(backgroundColor,"backgroundColor");
				HX_STACK_LINE(231)
				int countAround = this->howManyAroundNot(x,y,(int)0);		HX_STACK_VAR(countAround,"countAround");
				HX_STACK_LINE(236)
				if (((  ((!(((backgroundColor == ::StringTools_obj::hex((int)-5878708,null())))))) ? bool((this->howManyAroundInBackground(x,y,(int)-5878708) > (int)2)) : bool(true) ))){
					HX_STACK_LINE(238)
					Array< int > _g2 = Array_obj< int >::__new().Add((int)1).Add((int)3).Add((int)5).Add((int)7);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(238)
					this->applyRule(x,y,_g2,Array_obj< int >::__new().Add((int)1).Add((int)3).Add((int)5).Add((int)7),(int)-16777216);
				}
				HX_STACK_LINE(243)
				int colorFadeOut = this->colorLighter(this->pixelsBuffer->getPixel32(x,y));		HX_STACK_VAR(colorFadeOut,"colorFadeOut");
				HX_STACK_LINE(245)
				::String _g11 = ::StringTools_obj::hex(colorFadeOut,null());		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(245)
				if (((_g11 == ::StringTools_obj::hex((int)0,null())))){
					HX_STACK_LINE(247)
					this->pixels->setPixel32(x,y,(int)0);
				}
				HX_STACK_LINE(250)
				if (((pixelColor != ::StringTools_obj::hex((int)0,null())))){
					HX_STACK_LINE(253)
					if (((backgroundColor == ::StringTools_obj::hex((int)-33515,null())))){
						HX_STACK_LINE(255)
						this->moveFromTo(x,y,(int)-1,(int)0,colorFadeOut);
					}
					else{
						HX_STACK_LINE(257)
						if (((backgroundColor == ::StringTools_obj::hex((int)-5841844,null())))){
							HX_STACK_LINE(259)
							this->moveFromTo(x,y,(int)0,(int)-1,(int)-16777216);
						}
						else{
							HX_STACK_LINE(261)
							if (((backgroundColor == ::StringTools_obj::hex((int)-15083,null())))){
								HX_STACK_LINE(263)
								this->moveFromTo(x,y,(int)0,(int)1,(int)-16777216);
							}
							else{
								HX_STACK_LINE(265)
								if (((backgroundColor == ::StringTools_obj::hex((int)-11757604,null())))){
									HX_STACK_LINE(267)
									this->moveFromTo(x,y,(int)1,(int)0,(int)-16777216);
								}
								else{
									HX_STACK_LINE(269)
									if (((backgroundColor == ::StringTools_obj::hex((int)-1,null())))){
										HX_STACK_LINE(271)
										this->pixels->setPixel32(x,y,(int)0);
									}
								}
							}
						}
					}
				}
			}
		}
		HX_STACK_LINE(276)
		this->pixelsBuffer = this->pixels->clone();
		HX_STACK_LINE(277)
		this->pixels->unlock(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onTimer,(void))

Void Main_obj::onKeyDown( ::flash::events::KeyboardEvent event){
{
		HX_STACK_FRAME("Main","onKeyDown",0x547b59ed,"Main.onKeyDown","Main.hx",286,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(286)
		int _g = event->keyCode;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(286)
		int _switch_1 = (_g);
		if (  ( _switch_1==::flash::ui::Keyboard_obj::W)){
			HX_STACK_LINE(287)
			this->movingUp = true;
		}
		else if (  ( _switch_1==::flash::ui::Keyboard_obj::Z)){
			HX_STACK_LINE(288)
			this->movingUp = true;
		}
		else if (  ( _switch_1==::flash::ui::Keyboard_obj::S)){
			HX_STACK_LINE(289)
			this->movingDown = true;
		}
		else if (  ( _switch_1==::flash::ui::Keyboard_obj::A)){
			HX_STACK_LINE(290)
			this->movingLeft = true;
		}
		else if (  ( _switch_1==::flash::ui::Keyboard_obj::Q)){
			HX_STACK_LINE(291)
			this->movingLeft = true;
		}
		else if (  ( _switch_1==::flash::ui::Keyboard_obj::D)){
			HX_STACK_LINE(292)
			this->movingRight = true;
		}
		else if (  ( _switch_1==::flash::ui::Keyboard_obj::SPACE)){
			HX_STACK_LINE(293)
			this->pickingColor = true;
		}
		else if (  ( _switch_1==::flash::ui::Keyboard_obj::NUMPAD_ADD)){
			HX_STACK_LINE(294)
			this->speedUp();
		}
		else if (  ( _switch_1==::flash::ui::Keyboard_obj::NUMPAD_SUBTRACT)){
			HX_STACK_LINE(295)
			this->speedDown();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onKeyDown,(void))

Void Main_obj::onKeyUp( ::flash::events::KeyboardEvent event){
{
		HX_STACK_FRAME("Main","onKeyUp",0xd96dbf26,"Main.onKeyUp","Main.hx",300,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(300)
		int _g = event->keyCode;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(300)
		int _switch_2 = (_g);
		if (  ( _switch_2==::flash::ui::Keyboard_obj::W)){
			HX_STACK_LINE(301)
			this->movingUp = false;
		}
		else if (  ( _switch_2==::flash::ui::Keyboard_obj::Z)){
			HX_STACK_LINE(302)
			this->movingUp = false;
		}
		else if (  ( _switch_2==::flash::ui::Keyboard_obj::S)){
			HX_STACK_LINE(303)
			this->movingDown = false;
		}
		else if (  ( _switch_2==::flash::ui::Keyboard_obj::A)){
			HX_STACK_LINE(304)
			this->movingLeft = false;
		}
		else if (  ( _switch_2==::flash::ui::Keyboard_obj::Q)){
			HX_STACK_LINE(305)
			this->movingLeft = false;
		}
		else if (  ( _switch_2==::flash::ui::Keyboard_obj::D)){
			HX_STACK_LINE(306)
			this->movingRight = false;
		}
		else if (  ( _switch_2==::flash::ui::Keyboard_obj::SPACE)){
			HX_STACK_LINE(307)
			this->pickingColor = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onKeyUp,(void))

Void Main_obj::onMouseDown( ::flash::events::MouseEvent event){
{
		HX_STACK_FRAME("Main","onMouseDown",0x100c4c73,"Main.onMouseDown","Main.hx",312,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(312)
		this->mouseClic = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onMouseDown,(void))

Void Main_obj::onMouseUp( ::flash::events::MouseEvent event){
{
		HX_STACK_FRAME("Main","onMouseUp",0x78a6e42c,"Main.onMouseUp","Main.hx",315,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(316)
		this->mouseClic = false;
		HX_STACK_LINE(317)
		this->pickingColor = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onMouseUp,(void))

Void Main_obj::onEnterFrame( ::flash::events::Event event){
{
		HX_STACK_FRAME("Main","onEnterFrame",0x016e4b29,"Main.onEnterFrame","Main.hx",322,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(326)
		if ((this->mouseClic)){
			HX_STACK_LINE(327)
			int x = ::Math_obj::floor(this->background->get_mouseX());		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(328)
			int y = ::Math_obj::floor(this->background->get_mouseY());		HX_STACK_VAR(y,"y");
			HX_STACK_LINE(329)
			if ((this->pickingColor)){
				HX_STACK_LINE(330)
				this->brushColor = this->pixelsBackground->getPixel32(x,y);
				HX_STACK_LINE(331)
				this->pickingColor = false;
			}
			HX_STACK_LINE(334)
			this->pixelsBackground->setPixel32(x,y,this->brushColor);
			HX_STACK_LINE(335)
			this->pixelsBackground->setPixel32(x,(y - (int)1),this->brushColor);
			HX_STACK_LINE(336)
			this->pixelsBackground->setPixel32((x - (int)1),y,this->brushColor);
			HX_STACK_LINE(337)
			this->pixelsBackground->setPixel32(x,(y + (int)1),this->brushColor);
			HX_STACK_LINE(338)
			this->pixelsBackground->setPixel32((x + (int)1),y,this->brushColor);
		}
		HX_STACK_LINE(345)
		if ((this->movingUp)){
			HX_STACK_LINE(346)
			if (((this->velocityY >= 0.0))){
				HX_STACK_LINE(346)
				this->velocityY = -1.0;
			}
			HX_STACK_LINE(347)
			this->velocityY = ::Math_obj::max(-200.,(this->velocityY * this->accelerator));
		}
		else{
			HX_STACK_LINE(348)
			if ((this->movingDown)){
				HX_STACK_LINE(349)
				if (((this->velocityY <= 0.0))){
					HX_STACK_LINE(349)
					this->velocityY = 1.0;
				}
				HX_STACK_LINE(350)
				this->velocityY = ::Math_obj::min(200.0,(this->velocityY * this->accelerator));
			}
			else{
				HX_STACK_LINE(352)
				if (((bool((this->velocityY <= -0.01)) || bool((this->velocityY >= 0.01))))){
					HX_STACK_LINE(353)
					this->velocityY = (this->velocityY * this->deccelerator);
				}
				else{
					HX_STACK_LINE(355)
					this->velocityY = 0.0;
				}
			}
		}
		HX_STACK_LINE(358)
		if ((this->movingLeft)){
			HX_STACK_LINE(359)
			if (((this->velocityX >= 0.0))){
				HX_STACK_LINE(359)
				this->velocityX = (int)-1;
			}
			HX_STACK_LINE(360)
			this->velocityX = ::Math_obj::max(-200.,(this->velocityX * this->accelerator));
		}
		else{
			HX_STACK_LINE(361)
			if ((this->movingRight)){
				HX_STACK_LINE(362)
				if (((this->velocityX <= 0.0))){
					HX_STACK_LINE(362)
					this->velocityX = (int)1;
				}
				HX_STACK_LINE(363)
				this->velocityX = ::Math_obj::min(200.0,(this->velocityX * this->accelerator));
			}
			else{
				HX_STACK_LINE(365)
				if (((bool((this->velocityX <= -0.01)) || bool((this->velocityX >= 0.01))))){
					HX_STACK_LINE(366)
					this->velocityX = (this->velocityX * this->deccelerator);
				}
				else{
					HX_STACK_LINE(368)
					this->velocityX = 0.0;
				}
			}
		}
		HX_STACK_LINE(372)
		Float delta = (Float(((::flash::Lib_obj::getTimer() - this->timeLast))) / Float(1000.0));		HX_STACK_VAR(delta,"delta");
		HX_STACK_LINE(373)
		{
			HX_STACK_LINE(373)
			::flash::display::Sprite _g = this->scene;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(373)
			_g->set_x((_g->get_x() - (this->velocityX * delta)));
		}
		HX_STACK_LINE(374)
		{
			HX_STACK_LINE(374)
			::flash::display::Sprite _g = this->scene;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(374)
			_g->set_y((_g->get_y() - (this->velocityY * delta)));
		}
		HX_STACK_LINE(375)
		this->timeLast = ::flash::Lib_obj::getTimer();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onEnterFrame,(void))

Array< int > Main_obj::whichColorsAreHere( int x,int y){
	HX_STACK_FRAME("Main","whichColorsAreHere",0x7b7abd6c,"Main.whichColorsAreHere","Main.hx",378,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_LINE(379)
	Array< int > colorsArray = Array_obj< int >::__new();		HX_STACK_VAR(colorsArray,"colorsArray");
	HX_STACK_LINE(380)
	::flash::utils::ByteArray pixelsArray = this->pixelsBuffer->getPixels(::flash::geom::Rectangle_obj::__new((x - (int)1),(y - (int)1),(int)3,(int)3));		HX_STACK_VAR(pixelsArray,"pixelsArray");
	HX_STACK_LINE(381)
	{
		HX_STACK_LINE(381)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(381)
		int _g = pixelsArray->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(381)
		while(((_g1 < _g))){
			HX_STACK_LINE(381)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(382)
			colorsArray->push(pixelsArray->__get(i));
		}
	}
	HX_STACK_LINE(384)
	return colorsArray;
}


HX_DEFINE_DYNAMIC_FUNC2(Main_obj,whichColorsAreHere,return )

int Main_obj::howManyAround( int x,int y,int target){
	HX_STACK_FRAME("Main","howManyAround",0x81d6b727,"Main.howManyAround","Main.hx",387,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(target,"target")
	HX_STACK_LINE(388)
	int count = (int)0;		HX_STACK_VAR(count,"count");
	HX_STACK_LINE(389)
	if ((this->testPosition(x,y))){
		HX_STACK_LINE(390)
		{
			HX_STACK_LINE(390)
			int _g = (int)-1;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(390)
			while(((_g < (int)2))){
				HX_STACK_LINE(390)
				int row = (_g)++;		HX_STACK_VAR(row,"row");
				HX_STACK_LINE(391)
				{
					HX_STACK_LINE(391)
					int _g1 = (int)-1;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(391)
					while(((_g1 < (int)2))){
						HX_STACK_LINE(391)
						int col = (_g1)++;		HX_STACK_VAR(col,"col");
						HX_STACK_LINE(392)
						if ((this->testPosition((x + row),(y + col)))){
							HX_STACK_LINE(393)
							if (((((bool((row == (int)0)) && bool((col == (int)0)))) == false))){
								HX_STACK_LINE(394)
								::String _g2 = ::StringTools_obj::hex(this->pixelsBuffer->getPixel32((x + row),(y + col)),null());		HX_STACK_VAR(_g2,"_g2");
								HX_STACK_LINE(394)
								if (((_g2 == ::StringTools_obj::hex(target,null())))){
									HX_STACK_LINE(395)
									(count)++;
								}
							}
						}
					}
				}
			}
		}
		HX_STACK_LINE(401)
		return count;
	}
	else{
		HX_STACK_LINE(403)
		return (int)-1;
	}
	HX_STACK_LINE(389)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC3(Main_obj,howManyAround,return )

int Main_obj::howManyAroundNot( int x,int y,int target){
	HX_STACK_FRAME("Main","howManyAroundNot",0xd7f88c2c,"Main.howManyAroundNot","Main.hx",407,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(target,"target")
	HX_STACK_LINE(408)
	int count = (int)0;		HX_STACK_VAR(count,"count");
	HX_STACK_LINE(409)
	if ((this->testPosition(x,y))){
		HX_STACK_LINE(410)
		{
			HX_STACK_LINE(410)
			int _g = (int)-1;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(410)
			while(((_g < (int)2))){
				HX_STACK_LINE(410)
				int row = (_g)++;		HX_STACK_VAR(row,"row");
				HX_STACK_LINE(411)
				{
					HX_STACK_LINE(411)
					int _g1 = (int)-1;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(411)
					while(((_g1 < (int)2))){
						HX_STACK_LINE(411)
						int col = (_g1)++;		HX_STACK_VAR(col,"col");
						HX_STACK_LINE(412)
						if ((this->testPosition((x + row),(y + col)))){
							HX_STACK_LINE(413)
							if (((((bool((row == (int)0)) && bool((col == (int)0)))) == false))){
								HX_STACK_LINE(414)
								::String _g2 = ::StringTools_obj::hex(this->pixelsBuffer->getPixel32((x + row),(y + col)),null());		HX_STACK_VAR(_g2,"_g2");
								HX_STACK_LINE(414)
								if (((_g2 != ::StringTools_obj::hex(target,null())))){
									HX_STACK_LINE(415)
									(count)++;
								}
							}
						}
					}
				}
			}
		}
		HX_STACK_LINE(421)
		return count;
	}
	else{
		HX_STACK_LINE(423)
		return (int)-1;
	}
	HX_STACK_LINE(409)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC3(Main_obj,howManyAroundNot,return )

int Main_obj::howManyAroundInBackground( int x,int y,int colorTarget){
	HX_STACK_FRAME("Main","howManyAroundInBackground",0x60d745fa,"Main.howManyAroundInBackground","Main.hx",428,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(colorTarget,"colorTarget")
	HX_STACK_LINE(429)
	int count = (int)0;		HX_STACK_VAR(count,"count");
	HX_STACK_LINE(430)
	if ((this->testPosition(x,y))){
		HX_STACK_LINE(431)
		{
			HX_STACK_LINE(431)
			int _g = (int)-1;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(431)
			while(((_g < (int)2))){
				HX_STACK_LINE(431)
				int row = (_g)++;		HX_STACK_VAR(row,"row");
				HX_STACK_LINE(432)
				{
					HX_STACK_LINE(432)
					int _g1 = (int)-1;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(432)
					while(((_g1 < (int)2))){
						HX_STACK_LINE(432)
						int col = (_g1)++;		HX_STACK_VAR(col,"col");
						HX_STACK_LINE(433)
						if ((this->testPosition((x + row),(y + col)))){
							HX_STACK_LINE(434)
							if (((((bool((row == (int)0)) && bool((col == (int)0)))) == false))){
								HX_STACK_LINE(435)
								::String _g2 = ::StringTools_obj::hex(this->pixelsBackground->getPixel32((x + row),(y + col)),null());		HX_STACK_VAR(_g2,"_g2");
								HX_STACK_LINE(435)
								if (((_g2 == ::StringTools_obj::hex(colorTarget,null())))){
									HX_STACK_LINE(436)
									(count)++;
								}
							}
						}
					}
				}
			}
		}
		HX_STACK_LINE(442)
		return count;
	}
	else{
		HX_STACK_LINE(444)
		return (int)-1;
	}
	HX_STACK_LINE(430)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC3(Main_obj,howManyAroundInBackground,return )

int Main_obj::howManyAroundNotAndIn( int x,int y,int target,int colorEnvironment){
	HX_STACK_FRAME("Main","howManyAroundNotAndIn",0x894d22d0,"Main.howManyAroundNotAndIn","Main.hx",448,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(target,"target")
	HX_STACK_ARG(colorEnvironment,"colorEnvironment")
	HX_STACK_LINE(449)
	int count = (int)0;		HX_STACK_VAR(count,"count");
	HX_STACK_LINE(450)
	if ((this->testPosition(x,y))){
		HX_STACK_LINE(451)
		{
			HX_STACK_LINE(451)
			int _g = (int)-1;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(451)
			while(((_g < (int)2))){
				HX_STACK_LINE(451)
				int row = (_g)++;		HX_STACK_VAR(row,"row");
				HX_STACK_LINE(452)
				{
					HX_STACK_LINE(452)
					int _g1 = (int)-1;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(452)
					while(((_g1 < (int)2))){
						HX_STACK_LINE(452)
						int col = (_g1)++;		HX_STACK_VAR(col,"col");
						HX_STACK_LINE(453)
						if ((this->testPosition((x + row),(y + col)))){
							HX_STACK_LINE(454)
							if (((((bool((row == (int)0)) && bool((col == (int)0)))) == false))){
								HX_STACK_LINE(455)
								::String _g2 = ::StringTools_obj::hex(this->pixelsBuffer->getPixel32((x + row),(y + col)),null());		HX_STACK_VAR(_g2,"_g2");
								struct _Function_8_1{
									inline static bool Block( ::Main_obj *__this,int &x,int &colorEnvironment,int &y,int &col,int &row){
										HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",456,0x087e5c05)
										{
											HX_STACK_LINE(456)
											::String _g11 = ::StringTools_obj::hex(__this->pixelsBackground->getPixel32((x + row),(y + col)),null());		HX_STACK_VAR(_g11,"_g11");
											HX_STACK_LINE(456)
											return (_g11 == ::StringTools_obj::hex(colorEnvironment,null()));
										}
										return null();
									}
								};
								HX_STACK_LINE(455)
								if (((  (((_g2 != ::StringTools_obj::hex(target,null())))) ? bool(_Function_8_1::Block(this,x,colorEnvironment,y,col,row)) : bool(false) ))){
									HX_STACK_LINE(457)
									(count)++;
								}
							}
						}
					}
				}
			}
		}
		HX_STACK_LINE(463)
		return count;
	}
	else{
		HX_STACK_LINE(465)
		return (int)-1;
	}
	HX_STACK_LINE(450)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC4(Main_obj,howManyAroundNotAndIn,return )

Void Main_obj::zoom( ){
{
		HX_STACK_FRAME("Main","zoom",0xf5b08b48,"Main.zoom","Main.hx",469,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(470)
		this->pixelSize = ::Math_obj::max(1.0,::Math_obj::min((this->pixelSize + 1.0),40.0));
		HX_STACK_LINE(471)
		this->image->set_scaleX(this->image->set_scaleY(this->pixelSize));
		HX_STACK_LINE(472)
		this->background->set_scaleX(this->background->set_scaleY(this->pixelSize));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,zoom,(void))

Void Main_obj::unZoom( ){
{
		HX_STACK_FRAME("Main","unZoom",0x8a50f581,"Main.unZoom","Main.hx",475,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(476)
		this->pixelSize = ::Math_obj::max(1.0,::Math_obj::min((this->pixelSize - 1.0),40.0));
		HX_STACK_LINE(477)
		this->image->set_scaleX(this->image->set_scaleY(this->pixelSize));
		HX_STACK_LINE(478)
		this->background->set_scaleX(this->background->set_scaleY(this->pixelSize));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,unZoom,(void))

Void Main_obj::speedUp( ){
{
		HX_STACK_FRAME("Main","speedUp",0x44d578ad,"Main.speedUp","Main.hx",482,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(482)
		this->timer->set_delay(::Math_obj::max(10.0,::Math_obj::min((this->timer->get_delay() * 0.5),1000.0)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,speedUp,(void))

Void Main_obj::speedDown( ){
{
		HX_STACK_FRAME("Main","speedDown",0x3469c334,"Main.speedDown","Main.hx",486,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(486)
		this->timer->set_delay(::Math_obj::max(10.0,::Math_obj::min((this->timer->get_delay() * 2.0),1000.0)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,speedDown,(void))

bool Main_obj::testPosition( int x,int y){
	HX_STACK_FRAME("Main","testPosition",0x64dc6c50,"Main.testPosition","Main.hx",490,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_LINE(490)
	return (bool((bool((bool((x >= (int)0)) && bool((x < this->dimension)))) && bool((y >= (int)0)))) && bool((y < this->dimension)));
}


HX_DEFINE_DYNAMIC_FUNC2(Main_obj,testPosition,return )

Float Main_obj::MAX_SPEED;

int Main_obj::colorWhite;

int Main_obj::colorRed;

int Main_obj::colorRedDark;

int Main_obj::colorGreen;

int Main_obj::colorBlue;

int Main_obj::colorYellow;

int Main_obj::colorPurple;

int Main_obj::colorBlueDark;

int Main_obj::colorPurpleDark;

int Main_obj::colorOrange;

int Main_obj::colorGreenDark;

int Main_obj::colorAlive;

int Main_obj::colorDead;


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(scene,"scene");
	HX_MARK_MEMBER_NAME(dimension,"dimension");
	HX_MARK_MEMBER_NAME(pixelSize,"pixelSize");
	HX_MARK_MEMBER_NAME(image,"image");
	HX_MARK_MEMBER_NAME(background,"background");
	HX_MARK_MEMBER_NAME(pixels,"pixels");
	HX_MARK_MEMBER_NAME(pixelsBuffer,"pixelsBuffer");
	HX_MARK_MEMBER_NAME(pixelsBackground,"pixelsBackground");
	HX_MARK_MEMBER_NAME(timeLast,"timeLast");
	HX_MARK_MEMBER_NAME(timer,"timer");
	HX_MARK_MEMBER_NAME(fps,"fps");
	HX_MARK_MEMBER_NAME(debug,"debug");
	HX_MARK_MEMBER_NAME(debugCellsCount,"debugCellsCount");
	HX_MARK_MEMBER_NAME(cellsCount,"cellsCount");
	HX_MARK_MEMBER_NAME(colors,"colors");
	HX_MARK_MEMBER_NAME(velocityX,"velocityX");
	HX_MARK_MEMBER_NAME(velocityY,"velocityY");
	HX_MARK_MEMBER_NAME(movingUp,"movingUp");
	HX_MARK_MEMBER_NAME(movingDown,"movingDown");
	HX_MARK_MEMBER_NAME(movingLeft,"movingLeft");
	HX_MARK_MEMBER_NAME(movingRight,"movingRight");
	HX_MARK_MEMBER_NAME(mouseClic,"mouseClic");
	HX_MARK_MEMBER_NAME(pickingColor,"pickingColor");
	HX_MARK_MEMBER_NAME(brushColor,"brushColor");
	HX_MARK_MEMBER_NAME(accelerator,"accelerator");
	HX_MARK_MEMBER_NAME(deccelerator,"deccelerator");
	::flash::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(scene,"scene");
	HX_VISIT_MEMBER_NAME(dimension,"dimension");
	HX_VISIT_MEMBER_NAME(pixelSize,"pixelSize");
	HX_VISIT_MEMBER_NAME(image,"image");
	HX_VISIT_MEMBER_NAME(background,"background");
	HX_VISIT_MEMBER_NAME(pixels,"pixels");
	HX_VISIT_MEMBER_NAME(pixelsBuffer,"pixelsBuffer");
	HX_VISIT_MEMBER_NAME(pixelsBackground,"pixelsBackground");
	HX_VISIT_MEMBER_NAME(timeLast,"timeLast");
	HX_VISIT_MEMBER_NAME(timer,"timer");
	HX_VISIT_MEMBER_NAME(fps,"fps");
	HX_VISIT_MEMBER_NAME(debug,"debug");
	HX_VISIT_MEMBER_NAME(debugCellsCount,"debugCellsCount");
	HX_VISIT_MEMBER_NAME(cellsCount,"cellsCount");
	HX_VISIT_MEMBER_NAME(colors,"colors");
	HX_VISIT_MEMBER_NAME(velocityX,"velocityX");
	HX_VISIT_MEMBER_NAME(velocityY,"velocityY");
	HX_VISIT_MEMBER_NAME(movingUp,"movingUp");
	HX_VISIT_MEMBER_NAME(movingDown,"movingDown");
	HX_VISIT_MEMBER_NAME(movingLeft,"movingLeft");
	HX_VISIT_MEMBER_NAME(movingRight,"movingRight");
	HX_VISIT_MEMBER_NAME(mouseClic,"mouseClic");
	HX_VISIT_MEMBER_NAME(pickingColor,"pickingColor");
	HX_VISIT_MEMBER_NAME(brushColor,"brushColor");
	HX_VISIT_MEMBER_NAME(accelerator,"accelerator");
	HX_VISIT_MEMBER_NAME(deccelerator,"deccelerator");
	::flash::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"fps") ) { return fps; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { return zoom_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scene") ) { return scene; }
		if (HX_FIELD_EQ(inName,"image") ) { return image; }
		if (HX_FIELD_EQ(inName,"timer") ) { return timer; }
		if (HX_FIELD_EQ(inName,"debug") ) { return debug; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"pixels") ) { return pixels; }
		if (HX_FIELD_EQ(inName,"colors") ) { return colors; }
		if (HX_FIELD_EQ(inName,"unZoom") ) { return unZoom_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onTimer") ) { return onTimer_dyn(); }
		if (HX_FIELD_EQ(inName,"onKeyUp") ) { return onKeyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"speedUp") ) { return speedUp_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"timeLast") ) { return timeLast; }
		if (HX_FIELD_EQ(inName,"movingUp") ) { return movingUp; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"dimension") ) { return dimension; }
		if (HX_FIELD_EQ(inName,"pixelSize") ) { return pixelSize; }
		if (HX_FIELD_EQ(inName,"velocityX") ) { return velocityX; }
		if (HX_FIELD_EQ(inName,"velocityY") ) { return velocityY; }
		if (HX_FIELD_EQ(inName,"mouseClic") ) { return mouseClic; }
		if (HX_FIELD_EQ(inName,"applyRule") ) { return applyRule_dyn(); }
		if (HX_FIELD_EQ(inName,"onKeyDown") ) { return onKeyDown_dyn(); }
		if (HX_FIELD_EQ(inName,"onMouseUp") ) { return onMouseUp_dyn(); }
		if (HX_FIELD_EQ(inName,"speedDown") ) { return speedDown_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return background; }
		if (HX_FIELD_EQ(inName,"cellsCount") ) { return cellsCount; }
		if (HX_FIELD_EQ(inName,"movingDown") ) { return movingDown; }
		if (HX_FIELD_EQ(inName,"movingLeft") ) { return movingLeft; }
		if (HX_FIELD_EQ(inName,"brushColor") ) { return brushColor; }
		if (HX_FIELD_EQ(inName,"moveFromTo") ) { return moveFromTo_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"movingRight") ) { return movingRight; }
		if (HX_FIELD_EQ(inName,"onMouseDown") ) { return onMouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"accelerator") ) { return accelerator; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"pixelsBuffer") ) { return pixelsBuffer; }
		if (HX_FIELD_EQ(inName,"pickingColor") ) { return pickingColor; }
		if (HX_FIELD_EQ(inName,"cellCountAdd") ) { return cellCountAdd_dyn(); }
		if (HX_FIELD_EQ(inName,"colorLighter") ) { return colorLighter_dyn(); }
		if (HX_FIELD_EQ(inName,"deccelerator") ) { return deccelerator; }
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"testPosition") ) { return testPosition_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"howManyAround") ) { return howManyAround_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"debugCellsCount") ) { return debugCellsCount; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"pixelsBackground") ) { return pixelsBackground; }
		if (HX_FIELD_EQ(inName,"howManyAroundNot") ) { return howManyAroundNot_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"whichColorsAreHere") ) { return whichColorsAreHere_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"howManyAroundNotAndIn") ) { return howManyAroundNotAndIn_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"howManyAroundInBackground") ) { return howManyAroundInBackground_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"fps") ) { fps=inValue.Cast< ::openfl::display::FPS >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scene") ) { scene=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"image") ) { image=inValue.Cast< ::flash::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"timer") ) { timer=inValue.Cast< ::flash::utils::Timer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"debug") ) { debug=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"pixels") ) { pixels=inValue.Cast< ::flash::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"colors") ) { colors=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"timeLast") ) { timeLast=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"movingUp") ) { movingUp=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"dimension") ) { dimension=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pixelSize") ) { pixelSize=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"velocityX") ) { velocityX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"velocityY") ) { velocityY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseClic") ) { mouseClic=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { background=inValue.Cast< ::flash::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cellsCount") ) { cellsCount=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"movingDown") ) { movingDown=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"movingLeft") ) { movingLeft=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"brushColor") ) { brushColor=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"movingRight") ) { movingRight=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"accelerator") ) { accelerator=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"pixelsBuffer") ) { pixelsBuffer=inValue.Cast< ::flash::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pickingColor") ) { pickingColor=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"deccelerator") ) { deccelerator=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"debugCellsCount") ) { debugCellsCount=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"pixelsBackground") ) { pixelsBackground=inValue.Cast< ::flash::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("scene"));
	outFields->push(HX_CSTRING("dimension"));
	outFields->push(HX_CSTRING("pixelSize"));
	outFields->push(HX_CSTRING("image"));
	outFields->push(HX_CSTRING("background"));
	outFields->push(HX_CSTRING("pixels"));
	outFields->push(HX_CSTRING("pixelsBuffer"));
	outFields->push(HX_CSTRING("pixelsBackground"));
	outFields->push(HX_CSTRING("timeLast"));
	outFields->push(HX_CSTRING("timer"));
	outFields->push(HX_CSTRING("fps"));
	outFields->push(HX_CSTRING("debug"));
	outFields->push(HX_CSTRING("debugCellsCount"));
	outFields->push(HX_CSTRING("cellsCount"));
	outFields->push(HX_CSTRING("colors"));
	outFields->push(HX_CSTRING("velocityX"));
	outFields->push(HX_CSTRING("velocityY"));
	outFields->push(HX_CSTRING("movingUp"));
	outFields->push(HX_CSTRING("movingDown"));
	outFields->push(HX_CSTRING("movingLeft"));
	outFields->push(HX_CSTRING("movingRight"));
	outFields->push(HX_CSTRING("mouseClic"));
	outFields->push(HX_CSTRING("pickingColor"));
	outFields->push(HX_CSTRING("brushColor"));
	outFields->push(HX_CSTRING("accelerator"));
	outFields->push(HX_CSTRING("deccelerator"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("MAX_SPEED"),
	HX_CSTRING("colorWhite"),
	HX_CSTRING("colorRed"),
	HX_CSTRING("colorRedDark"),
	HX_CSTRING("colorGreen"),
	HX_CSTRING("colorBlue"),
	HX_CSTRING("colorYellow"),
	HX_CSTRING("colorPurple"),
	HX_CSTRING("colorBlueDark"),
	HX_CSTRING("colorPurpleDark"),
	HX_CSTRING("colorOrange"),
	HX_CSTRING("colorGreenDark"),
	HX_CSTRING("colorAlive"),
	HX_CSTRING("colorDead"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flash::display::Sprite*/ ,(int)offsetof(Main_obj,scene),HX_CSTRING("scene")},
	{hx::fsInt,(int)offsetof(Main_obj,dimension),HX_CSTRING("dimension")},
	{hx::fsFloat,(int)offsetof(Main_obj,pixelSize),HX_CSTRING("pixelSize")},
	{hx::fsObject /*::flash::display::Bitmap*/ ,(int)offsetof(Main_obj,image),HX_CSTRING("image")},
	{hx::fsObject /*::flash::display::Bitmap*/ ,(int)offsetof(Main_obj,background),HX_CSTRING("background")},
	{hx::fsObject /*::flash::display::BitmapData*/ ,(int)offsetof(Main_obj,pixels),HX_CSTRING("pixels")},
	{hx::fsObject /*::flash::display::BitmapData*/ ,(int)offsetof(Main_obj,pixelsBuffer),HX_CSTRING("pixelsBuffer")},
	{hx::fsObject /*::flash::display::BitmapData*/ ,(int)offsetof(Main_obj,pixelsBackground),HX_CSTRING("pixelsBackground")},
	{hx::fsInt,(int)offsetof(Main_obj,timeLast),HX_CSTRING("timeLast")},
	{hx::fsObject /*::flash::utils::Timer*/ ,(int)offsetof(Main_obj,timer),HX_CSTRING("timer")},
	{hx::fsObject /*::openfl::display::FPS*/ ,(int)offsetof(Main_obj,fps),HX_CSTRING("fps")},
	{hx::fsObject /*::flash::text::TextField*/ ,(int)offsetof(Main_obj,debug),HX_CSTRING("debug")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Main_obj,debugCellsCount),HX_CSTRING("debugCellsCount")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Main_obj,cellsCount),HX_CSTRING("cellsCount")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Main_obj,colors),HX_CSTRING("colors")},
	{hx::fsFloat,(int)offsetof(Main_obj,velocityX),HX_CSTRING("velocityX")},
	{hx::fsFloat,(int)offsetof(Main_obj,velocityY),HX_CSTRING("velocityY")},
	{hx::fsBool,(int)offsetof(Main_obj,movingUp),HX_CSTRING("movingUp")},
	{hx::fsBool,(int)offsetof(Main_obj,movingDown),HX_CSTRING("movingDown")},
	{hx::fsBool,(int)offsetof(Main_obj,movingLeft),HX_CSTRING("movingLeft")},
	{hx::fsBool,(int)offsetof(Main_obj,movingRight),HX_CSTRING("movingRight")},
	{hx::fsBool,(int)offsetof(Main_obj,mouseClic),HX_CSTRING("mouseClic")},
	{hx::fsBool,(int)offsetof(Main_obj,pickingColor),HX_CSTRING("pickingColor")},
	{hx::fsInt,(int)offsetof(Main_obj,brushColor),HX_CSTRING("brushColor")},
	{hx::fsFloat,(int)offsetof(Main_obj,accelerator),HX_CSTRING("accelerator")},
	{hx::fsFloat,(int)offsetof(Main_obj,deccelerator),HX_CSTRING("deccelerator")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("scene"),
	HX_CSTRING("dimension"),
	HX_CSTRING("pixelSize"),
	HX_CSTRING("image"),
	HX_CSTRING("background"),
	HX_CSTRING("pixels"),
	HX_CSTRING("pixelsBuffer"),
	HX_CSTRING("pixelsBackground"),
	HX_CSTRING("timeLast"),
	HX_CSTRING("timer"),
	HX_CSTRING("fps"),
	HX_CSTRING("debug"),
	HX_CSTRING("debugCellsCount"),
	HX_CSTRING("cellsCount"),
	HX_CSTRING("colors"),
	HX_CSTRING("velocityX"),
	HX_CSTRING("velocityY"),
	HX_CSTRING("movingUp"),
	HX_CSTRING("movingDown"),
	HX_CSTRING("movingLeft"),
	HX_CSTRING("movingRight"),
	HX_CSTRING("mouseClic"),
	HX_CSTRING("pickingColor"),
	HX_CSTRING("brushColor"),
	HX_CSTRING("cellCountAdd"),
	HX_CSTRING("applyRule"),
	HX_CSTRING("moveFromTo"),
	HX_CSTRING("colorLighter"),
	HX_CSTRING("onTimer"),
	HX_CSTRING("onKeyDown"),
	HX_CSTRING("onKeyUp"),
	HX_CSTRING("onMouseDown"),
	HX_CSTRING("onMouseUp"),
	HX_CSTRING("accelerator"),
	HX_CSTRING("deccelerator"),
	HX_CSTRING("onEnterFrame"),
	HX_CSTRING("whichColorsAreHere"),
	HX_CSTRING("howManyAround"),
	HX_CSTRING("howManyAroundNot"),
	HX_CSTRING("howManyAroundInBackground"),
	HX_CSTRING("howManyAroundNotAndIn"),
	HX_CSTRING("zoom"),
	HX_CSTRING("unZoom"),
	HX_CSTRING("speedUp"),
	HX_CSTRING("speedDown"),
	HX_CSTRING("testPosition"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Main_obj::MAX_SPEED,"MAX_SPEED");
	HX_MARK_MEMBER_NAME(Main_obj::colorWhite,"colorWhite");
	HX_MARK_MEMBER_NAME(Main_obj::colorRed,"colorRed");
	HX_MARK_MEMBER_NAME(Main_obj::colorRedDark,"colorRedDark");
	HX_MARK_MEMBER_NAME(Main_obj::colorGreen,"colorGreen");
	HX_MARK_MEMBER_NAME(Main_obj::colorBlue,"colorBlue");
	HX_MARK_MEMBER_NAME(Main_obj::colorYellow,"colorYellow");
	HX_MARK_MEMBER_NAME(Main_obj::colorPurple,"colorPurple");
	HX_MARK_MEMBER_NAME(Main_obj::colorBlueDark,"colorBlueDark");
	HX_MARK_MEMBER_NAME(Main_obj::colorPurpleDark,"colorPurpleDark");
	HX_MARK_MEMBER_NAME(Main_obj::colorOrange,"colorOrange");
	HX_MARK_MEMBER_NAME(Main_obj::colorGreenDark,"colorGreenDark");
	HX_MARK_MEMBER_NAME(Main_obj::colorAlive,"colorAlive");
	HX_MARK_MEMBER_NAME(Main_obj::colorDead,"colorDead");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Main_obj::MAX_SPEED,"MAX_SPEED");
	HX_VISIT_MEMBER_NAME(Main_obj::colorWhite,"colorWhite");
	HX_VISIT_MEMBER_NAME(Main_obj::colorRed,"colorRed");
	HX_VISIT_MEMBER_NAME(Main_obj::colorRedDark,"colorRedDark");
	HX_VISIT_MEMBER_NAME(Main_obj::colorGreen,"colorGreen");
	HX_VISIT_MEMBER_NAME(Main_obj::colorBlue,"colorBlue");
	HX_VISIT_MEMBER_NAME(Main_obj::colorYellow,"colorYellow");
	HX_VISIT_MEMBER_NAME(Main_obj::colorPurple,"colorPurple");
	HX_VISIT_MEMBER_NAME(Main_obj::colorBlueDark,"colorBlueDark");
	HX_VISIT_MEMBER_NAME(Main_obj::colorPurpleDark,"colorPurpleDark");
	HX_VISIT_MEMBER_NAME(Main_obj::colorOrange,"colorOrange");
	HX_VISIT_MEMBER_NAME(Main_obj::colorGreenDark,"colorGreenDark");
	HX_VISIT_MEMBER_NAME(Main_obj::colorAlive,"colorAlive");
	HX_VISIT_MEMBER_NAME(Main_obj::colorDead,"colorDead");
};

#endif

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void Main_obj::__boot()
{
	MAX_SPEED= 200.0;
	colorWhite= (int)-1;
	colorRed= (int)-5878708;
	colorRedDark= (int)-5884852;
	colorGreen= (int)-5841844;
	colorBlue= (int)-11757604;
	colorYellow= (int)-15083;
	colorPurple= (int)-2795061;
	colorBlueDark= (int)-10919467;
	colorPurpleDark= (int)-8505992;
	colorOrange= (int)-33515;
	colorGreenDark= (int)-11371243;
	colorAlive= (int)-16777216;
	colorDead= (int)0;
}

