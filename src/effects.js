var Effects = {};

Effects.ColorWithRatio = function(ratio)
{
    // Color Rainbow
    if (Parameter.colors == "Rainbow") {
        return Color.GetRainbow(ratio);
    }
    // Color Gray
    else if (Parameter.colors == "Gray") {
        return Color.Gray(ratio);
    }
}

Effects.Waves = function() 
{
    var x, y, previousX, previousY;
    var line, color, c, perlin;
    
    // For each Lines
    for (var l = 0; l < Parameter.lineCount; ++l) {
        
        // Line translation
        line = (l + Engine.tick * Parameter.timeSpeedZ) % Parameter.lineCount;
        
        // Perlin noise
        perlin = noise({
            x: (line * Parameter.frequenceY + Engine.tick * Parameter.timeSpeedY) * Parameter.perlinScale, 
            y: 0, 
            z: Engine.tick * Parameter.timeSpeedX * Parameter.perlinScale});
        
        // Move line to first entry
        y = line * 8 * (1 + (perlin * 0.5 + 0.5));
        Drawer.graphics.moveTo(0, y);
        previousX = 0;
        previousY = y;

        // For each Segments of the line
        for (var i = 0; i <= Parameter.lineSegmentCount; ++i) {
            
            // Perlin noise
            perlin = noise({
                x: ((line + i) * Parameter.frequenceY + Engine.tick * Parameter.timeSpeedY) * Parameter.perlinScale, 
                y: 0, 
                z: (i * Parameter.frequenceX + Engine.tick * Parameter.timeSpeedX) * Parameter.perlinScale});
            
            // Segment position
            x = (i / Parameter.lineSegmentCount) * Drawer.frame.width;
            y = line * Parameter.lineSpace * (1 + (perlin * 0.5 + 0.5));

            // Color from the angle of segment
            if (Parameter.colorDot) {
                c = Math.abs( Utils.dot(
                    Utils.Normalize({ x: x - previousX, y: y - previousY})
                        , { x : 0, y: 1 } ) );
            }
            // Color from line percent
            else {
                c = line / Parameter.lineCount;
            }
            
            color = Effects.ColorWithRatio(c);
            
            // Draw line
            Drawer.graphics.lineStyle(Parameter.lineThickness, color);
            Drawer.graphics.lineTo(x, Drawer.frame.height - y);
            previousX = x;
            previousY = y;
        }
    }
}

Effects.Folds = function() 
{
    var time = Engine.tick * 0.01;
    var scale = 4;
    var lineCount = Drawer.frame.width / scale;
    var halfLineCount = lineCount / 2;
    var halfW = Drawer.frame.middle.x;
    var halfH = Drawer.frame.middle.y;
    var lineXStart = (halfW - halfLineCount * scale) / scale;
    var c, x, y, previousX, previousY;
    var anchorX = halfW + Math.cos(time) * Drawer.frame.min / 8;
    var anchorY = halfH + Math.sin(time) * Drawer.frame.min / 8;
    var vectorX = anchorX;
    var vectorY = Math.min(Drawer.frame.height, Drawer.frame.min + anchorY);

    for (var i = 0; i < lineCount; ++i) {
        
        
        if (i >= halfLineCount) {
            x = lineCount - i % halfLineCount;
        }
        else {
            x = i;
        }
        
        perlin = noise({
            x: (x * Parameter.frequenceX + Engine.tick * Parameter.timeSpeedX) * Parameter.perlinScale, 
            y: 0, 
            z: (x * Parameter.frequenceY + Engine.tick * Parameter.timeSpeedY) * Parameter.perlinScale});
        
        perlin = perlin * 0.5 + 0.5;
        
        
        var ratio = x / lineCount;
        x *= scale;
        x += lineXStart;
        y = Drawer.frame.height - perlin * (Drawer.frame.height * 0.125);

        c = Math.abs( Utils.dot(
            Utils.Normalize({ x: x - previousX, y: y - previousY})
                , { x : 0, y: 1 } ) );
        
        color = Effects.ColorWithRatio(c);
        
        Drawer.graphics.lineStyle(Parameter.lineThickness, color);
        
        var anchX = anchorX - 32 + ratio * 64;
        Drawer.graphics.moveTo(anchX, anchorY);      
//        Drawer.graphics.lineTo(x, y);
        Drawer.graphics.bezierCurveTo(anchX, anchorY, vectorX, vectorY, x, y);
        
        previousX = x;
        previousY = y;
    }
}