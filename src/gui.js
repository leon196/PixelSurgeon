// Parameters
var Parameter = {};
Parameter.clearAuto = false;
Parameter.globalScale = 4;
Parameter.drawing = true;

// Dat-gui
window.onload = function() {
	var gui = new dat.GUI();
	gui.domElement.id = 'gui';
	gui.add(Parameter, 'clearAuto');
	gui.add(Parameter, 'drawing');
	// gui.add(Parameter, 'message', [ 'pizza', 'chrome', 'hooray' ] );
	// gui.add(Parameter, 'speed', { Stopped: 0, Slow: 0.1, Fast: 5 } );
};