#ifndef INCLUDED_Main
#define INCLUDED_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/display/Sprite.h>
HX_DECLARE_CLASS0(Main)
HX_DECLARE_CLASS2(flash,display,Bitmap)
HX_DECLARE_CLASS2(flash,display,BitmapData)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,events,KeyboardEvent)
HX_DECLARE_CLASS2(flash,events,MouseEvent)
HX_DECLARE_CLASS2(flash,events,TimerEvent)
HX_DECLARE_CLASS2(flash,text,TextField)
HX_DECLARE_CLASS2(flash,utils,Timer)
HX_DECLARE_CLASS2(openfl,display,FPS)


class HXCPP_CLASS_ATTRIBUTES  Main_obj : public ::flash::display::Sprite_obj{
	public:
		typedef ::flash::display::Sprite_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Main"); }

		::flash::display::Sprite scene;
		int dimension;
		Float pixelSize;
		::flash::display::Bitmap image;
		::flash::display::Bitmap background;
		::flash::display::BitmapData pixels;
		::flash::display::BitmapData pixelsBuffer;
		::flash::display::BitmapData pixelsBackground;
		int timeLast;
		::flash::utils::Timer timer;
		::openfl::display::FPS fps;
		::flash::text::TextField debug;
		Array< ::Dynamic > debugCellsCount;
		Array< int > cellsCount;
		Array< int > colors;
		Float velocityX;
		Float velocityY;
		bool movingUp;
		bool movingDown;
		bool movingLeft;
		bool movingRight;
		bool mouseClic;
		bool pickingColor;
		int brushColor;
		virtual Void cellCountAdd( int indexColor);
		Dynamic cellCountAdd_dyn();

		virtual Void applyRule( int x,int y,Array< int > birth,Array< int > survive,int newColor);
		Dynamic applyRule_dyn();

		virtual Void moveFromTo( int fromX,int fromY,int offsetX,int offsetY,int newColor);
		Dynamic moveFromTo_dyn();

		virtual int colorLighter( int color);
		Dynamic colorLighter_dyn();

		virtual Void onTimer( ::flash::events::TimerEvent event);
		Dynamic onTimer_dyn();

		virtual Void onKeyDown( ::flash::events::KeyboardEvent event);
		Dynamic onKeyDown_dyn();

		virtual Void onKeyUp( ::flash::events::KeyboardEvent event);
		Dynamic onKeyUp_dyn();

		virtual Void onMouseDown( ::flash::events::MouseEvent event);
		Dynamic onMouseDown_dyn();

		virtual Void onMouseUp( ::flash::events::MouseEvent event);
		Dynamic onMouseUp_dyn();

		Float accelerator;
		Float deccelerator;
		virtual Void onEnterFrame( ::flash::events::Event event);
		Dynamic onEnterFrame_dyn();

		virtual Array< int > whichColorsAreHere( int x,int y);
		Dynamic whichColorsAreHere_dyn();

		virtual int howManyAround( int x,int y,int target);
		Dynamic howManyAround_dyn();

		virtual int howManyAroundNot( int x,int y,int target);
		Dynamic howManyAroundNot_dyn();

		virtual int howManyAroundInBackground( int x,int y,int colorTarget);
		Dynamic howManyAroundInBackground_dyn();

		virtual int howManyAroundNotAndIn( int x,int y,int target,int colorEnvironment);
		Dynamic howManyAroundNotAndIn_dyn();

		virtual Void zoom( );
		Dynamic zoom_dyn();

		virtual Void unZoom( );
		Dynamic unZoom_dyn();

		virtual Void speedUp( );
		Dynamic speedUp_dyn();

		virtual Void speedDown( );
		Dynamic speedDown_dyn();

		virtual bool testPosition( int x,int y);
		Dynamic testPosition_dyn();

		static Float MAX_SPEED;
		static int colorWhite;
		static int colorRed;
		static int colorRedDark;
		static int colorGreen;
		static int colorBlue;
		static int colorYellow;
		static int colorPurple;
		static int colorBlueDark;
		static int colorPurpleDark;
		static int colorOrange;
		static int colorGreenDark;
		static int colorAlive;
		static int colorDead;
};


#endif /* INCLUDED_Main */ 
