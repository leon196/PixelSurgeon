var Color = {};

Color.Red = 0xF26C4F;  	
Color.RedOrange = 0xF68E55;  	
Color.YellowOrange = 0xFBAF5C;  	
Color.Yellow = 0xFFF467;  	
Color.PeaGreen = 0xACD372;  	
Color.YellowGreen = 0x7CC576;  	
Color.Green = 0x3BB878;  	
Color.GreenCyan = 0x1ABBB4;  	
Color.Cyan = 0x00BFF3;  	
Color.CyanBlue = 0x438CCA;  	
Color.Blue = 0x5574B9;  	
Color.BlueViolet = 0x605CA8;  	
Color.Violet = 0x855FA8;  	
Color.VioletMagenta = 0xA763A8;  	
Color.Magenta = 0xF06EA9;  	
Color.MagentaRed = 0xF26D7D;

Color.colors = [Color.Red, Color.RedOrange, Color.YellowOrange, Color.Yellow, Color.PeaGreen, Color.YellowGreen, 
Color.Green, Color.GreenCyan, Color.Cyan, Color.CyanBlue, Color.Blue, Color.BlueViolet, Color.Violet, 
Color.VioletMagenta, Color.Magenta, Color.MagentaRed];

var rainbowColorCurrentIndex = 0;

Color.Rainbow = function () {
	rainbowColorCurrentIndex = (rainbowColorCurrentIndex + 1) % Color.colors.length;
	return Color.colors[rainbowColorCurrentIndex];
};

Color.GetRainbow = function(ratio) {
	var index = Math.floor(ratio * Color.colors.length);
	return Color.colors[index % Color.colors.length];
}

Color.Get = function(index) {
	return Color.colors[index % Color.colors.length];
}

Color.Gray10 = 0xEBEBEB;
Color.Gray15 = 0xE1E1E1;
Color.Gray20 = 0xD7D7D7;
Color.Gray25 = 0xD7D7D7;
Color.Gray30 = 0xC2C2C2;
Color.Gray35 = 0xB7B7B7;
Color.Gray40 = 0xACACAC;
Color.Gray45 = 0xA0A0A0;
Color.Gray50 = 0x959595;
Color.Gray55 = 0x898989;
Color.Gray60 = 0x7D7D7D;
Color.Gray65 = 0x707070;
Color.Gray70 = 0x626262;
Color.Gray75 = 0x555555;
Color.Gray80 = 0x464646;
Color.Gray85 = 0x363636;
Color.Gray90 = 0x262626;
Color.Gray95 = 0x111111;
Color.grays = [Color.Gray10, Color.Gray15, Color.Gray20, Color.Gray25, Color.Gray30, 
Color.Gray35, Color.Gray40, Color.Gray45, Color.Gray50, Color.Gray55, Color.Gray60, 
Color.Gray65, Color.Gray70, Color.Gray75, Color.Gray80, Color.Gray85, Color.Gray90, Color.Gray95];

Color.Gray = function(ratio) {
	var index = Math.floor(ratio * Color.grays.length);
	return Color.grays[index % Color.grays.length];
}