package lime;


import lime.utils.Assets;


class AssetData {

	private static var initialized:Bool = false;
	
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var path = new #if haxe3 Map <String, #else Hash <#end String> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();	
	
	public static function initialize():Void {
		
		if (!initialized) {
			
			path.set ("assets/map.png", "assets/map.png");
			type.set ("assets/map.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/map.xcf", "assets/map.xcf");
			type.set ("assets/map.xcf", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("assets/map_agents.png", "assets/map_agents.png");
			type.set ("assets/map_agents.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/openfl.png", "assets/openfl.png");
			type.set ("assets/openfl.png", Reflect.field (AssetType, "image".toUpperCase ()));
			
			
			initialized = true;
			
		} //!initialized
		
	} //initialize
	
	
} //AssetData
