// Parameters
var Parameter = {};

// Dat-gui
var gui;
var folders = [];

Parameter.debug = 0;
Parameter.clearAuto = true;
Parameter.paintMode = false;
Parameter.globalScale = 9;
Parameter.lineCount = 64;
Parameter.lineSegmentCount = 32; 
Parameter.lineSpace = 2.5;
Parameter.lineThickness = 1;
Parameter.timeSpeedX = 4;
Parameter.timeSpeedY = 4;
Parameter.timeSpeedZ = 0.01;
Parameter.perlinScale = 0.02;
Parameter.frequenceX = 2.5;
Parameter.frequenceY = 1.5;
Parameter.effects = 'Folds';
Parameter.templates = '1';
Parameter.colors = 'Gray';
Parameter.colorDot = false;
var effectsNameArray =  ['Waves', 'Folds'];
var effectTemplatesNameArray = ['1', '2', '3', '4'];
var effectColorsNameArray = ['Gray', 'Rainbow'];

Parameter.ChangeEffect = function(value) {
    switch (effectsNameArray.indexOf(value)) {
        default: break;
    }
};

Parameter.ChangeTemplate = function(value) {
    switch (effectTemplatesNameArray.indexOf(value)) {
        case 0:
            Parameter.TemplateFold1(); 
            break;
        case 1:
            Parameter.TemplateFold2();
            break;
        case 2:
            Parameter.TemplateFold3();
            break;
        case 3:
            Parameter.TemplateFold4();
            break;
    }
    // Iterate over all controllers
    for (var f in folders) {
        for (var i in folders[f].__controllers) {
            folders[f].__controllers[i].updateDisplay();
        }
    }

};

// Dat-gui
window.onload = function() {
	gui = new dat.GUI();
    gui.remember(Parameter);
    
	gui.domElement.id = 'gui';
//	var folderGeneral = gui.addFolder('general');
    
	gui.add(Parameter, 'debug').listen();
	gui.add(Parameter, 'clearAuto');
    
	gui.add(Parameter, 'effects', effectsNameArray)
        .onChange(function(value){ Parameter.ChangeEffect(value);});
    
	gui.add(Parameter, 'templates', effectTemplatesNameArray)
        .onChange(function(value){ Parameter.ChangeTemplate(value);});
    
	var folderColor = gui.addFolder('color');
	folderColor.add(Parameter, 'colors', effectColorsNameArray);
	folderColor.add(Parameter, 'colorDot');
    folderColor.open();
    
	var folderLine = gui.addFolder('line');
	folderLine.add(Parameter, 'lineCount', 16, 64).step(1);
	folderLine.add(Parameter, 'lineSegmentCount', 8, 32).step(1);
	folderLine.add(Parameter, 'lineSpace', 0, 4);
	folderLine.add(Parameter, 'lineThickness', 1, 8);
    folderLine.open();
    
    var folderTime = gui.addFolder('time');
	folderTime.add(Parameter, 'timeSpeedX', 0, 0.5);
	folderTime.add(Parameter, 'timeSpeedY', 0, 0.5);
	folderTime.add(Parameter, 'timeSpeedZ', 0, 0.125);
    folderTime.open();
    
    var folderNoise = gui.addFolder('noise');
	folderNoise.add(Parameter, 'perlinScale', 0.001, 0.09);
	folderNoise.add(Parameter, 'frequenceX', 0, 4);
	folderNoise.add(Parameter, 'frequenceY', 0, 4);
    folderNoise.open();
    
    folders.push(folderColor);
    folders.push(folderLine);
    folders.push(folderTime);
    folders.push(folderNoise);
    
    gui.close();
};

// Templates
Parameter.TemplateFold1 = function() {
    Parameter.colors =              'Gray';
    Parameter.colorDot =            false;
    Parameter.lineCount =           64;
    Parameter.lineSegmentCount =    32; 
    Parameter.lineSpace =           2.5;
    Parameter.lineThickness =       1;
    Parameter.timeSpeedX =          0.4;
    Parameter.timeSpeedY =          0.4;
    Parameter.timeSpeedZ =          0.01;
    Parameter.perlinScale =         0.08;
    Parameter.frequenceX =          2.5;
    Parameter.frequenceY =          1.5;
};
Parameter.TemplateFold2 = function() {
    Parameter.colors =              'Rainbow';
    Parameter.colorDot =            true;
    Parameter.lineCount =           64;
    Parameter.lineSegmentCount =    32; 
    Parameter.lineSpace =           4;
    Parameter.lineThickness =       1;
    Parameter.timeSpeedX =          0.4;
    Parameter.timeSpeedY =          0.4;
    Parameter.timeSpeedZ =          0.01;
    Parameter.perlinScale =         0.08;
    Parameter.frequenceX =          1.8;
    Parameter.frequenceY =          0.7;
};
Parameter.TemplateFold3 = function() {
    Parameter.colors =              'Gray';
    Parameter.colorDot =            false;
    Parameter.lineCount =           64;
    Parameter.lineSegmentCount =    32; 
    Parameter.lineSpace =           0.9;
    Parameter.lineThickness =       4;
    Parameter.timeSpeedX =          0.4;
    Parameter.timeSpeedY =          0.4;
    Parameter.timeSpeedZ =          0.01;
    Parameter.perlinScale =         0.09;
    Parameter.frequenceX =          1.8;
    Parameter.frequenceY =          0.6;
};
Parameter.TemplateFold4 = function() {
    Parameter.colors =              'Rainbow';
    Parameter.colorDot =            false;
    Parameter.lineCount =           64;
    Parameter.lineSegmentCount =    32; 
    Parameter.lineSpace =           2.1;
    Parameter.lineThickness =       1;
    Parameter.timeSpeedX =          0.26;
    Parameter.timeSpeedY =          0.5;
    Parameter.timeSpeedZ =          0.0;
    Parameter.perlinScale =         0.09;
    Parameter.frequenceX =          4.0;
    Parameter.frequenceY =          0.7;
};