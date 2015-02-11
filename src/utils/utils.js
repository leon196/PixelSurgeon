var Utils = {};
// Maths
Utils.pi = 3.1415926535897932384626433832795;
Utils.pi2 = 6.283185307179586476925286766559;


Utils.Segment = function (value_, segmentCount_) { return Math.floor( value_ * segmentCount_ ) / segmentCount_ ; };

Utils.Distance = function (v1, v2) { return Math.sqrt((v2.x - v1.x) * (v2.x - v1.x) + (v2.y - v1.y) * (v2.y - v1.y)); };

Utils.Length = function (v) { return Math.sqrt(v.x * v.x + v.y * v.y); };

Utils.Normalize = function (v) { var dist = Utils.Distance(v, {x:0, y:0}); return { x: v.x / dist, y: v.y / dist }; }

////////////////////////////////////
// From -> http://www.actionscript.org/forums/showthread.php3?t=176052
// By abeall
// dot product of two vectors 
Utils.dot = function (v1,v2) { return (v1.x*v2.x) + (v1.y*v2.y); } ;
// reflect vector 'v' against normalized vector 'n' 
Utils.Reflect = function (v, n) {     
	// R = V - 2 * (V · N)     
	var d = Utils.dot(v,n);  
	return { x: v.x -2 * d * n.x, y: v.y -2 * d * n.y } 
};
////////////////////////////////////


function fract(x) { return x % 1; }
function fractVec3(v) { return { x: v.x % 1, y: v.y % 1 , z: v.z % 1}; }
function mix(a, b, ratio) { return a * (1 - ratio) + b * ratio };

////////////////////////////////////
// hash based 3d value noise
// function taken from [url]https://www.shadertoy.com/view/XslGRr[/url]
// Created by inigo quilez - iq/2013
// License Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.
// ported from HLSL to js
function hash( n ) {
	return fract(Math.sin(n)*43758.5453);
}
function noise( seed ) {
    // The noise function returns a value in the range -1.0f -> 1.0f
    var p = { x: Math.floor(seed.x), y : Math.floor(seed.y), z: Math.floor(seed.z) };
    var f = fractVec3(seed);
    f.x = f.x*f.x*(3.0-2.0*f.x);
    f.y = f.y*f.y*(3.0-2.0*f.y);
    f.z = f.z*f.z*(3.0-2.0*f.z);
    var n = p.x + p.y*57.0 + 113.0*p.z;
    return mix(mix(mix( hash(n+0.0), hash(n+1.0),f.x),
                   mix( hash(n+57.0), hash(n+58.0),f.x),f.y),
               mix(mix( hash(n+113.0), hash(n+114.0),f.x),
                   mix( hash(n+170.0), hash(n+171.0),f.x),f.y),f.z);
}
////////////////////////////////////

Utils.SubVec2 = function (v1, v2) {
	return { x: v2.x - v1.x, y: v2.y - v1.y };
};

Utils.AddVec2 = function (v1, v2) {
	return { x: v2.x + v1.x, y: v2.y + v1.y };
};

Utils.LengthVec2 = function (v) {
	return Math.sqrt(v.x*v.x+v.y*v.y);
}

Utils.Vec2 = function (x_, y_)
{
	this.x = x_;
	this.y = y_;
};

Utils.Vec2Random = function ()
{
	return new Utils.Vec2(Math.random(), Math.random());
};

Utils.Vec2RandomDirection = function ()
{
	var rand = Math.random() * pi2;
	return new Utils.Vec2(Math.cos(rand), Math.sin(rand));
};

Utils.Vec2Spawn = function ()
{
	return new Utils.Vec2(
		marginWidth + Math.random() * (windowWidth - marginWidth * 2), 
		marginHeight + Math.random() * (windowHeight - marginHeight * 2));
};

Utils.Vec2Grid = function (index_)
{
	return new Utils.Vec2(
		gridAnchor.x + (index_ % gridDimension) * gridCellSize,
		gridAnchor.y + Math.floor(index_ / gridDimension) * gridCellSize);
};

Utils.Vec2Clipped = function (x_, y_)
{
	return new Utils.Vec2(
		Math.max(marginWidth, Math.min(windowWidth - marginWidth)),
		Math.max(marginHeight, Math.min(windowWidth - marginHeight)));
};

Utils.Vec2Direction = function (v1, v2) 
{
	var dist = Utils.Distance(v1, v2);
	return new Utils.Vec2((v2.x - v1.x) / dist, (v2.y - v1.y) / dist);
};

Utils.GetRandomUniqueNumbers = function (range_)
{
	var randomList = [];
	for (var i = 0; i < range_; ++i) { randomList[i] = i; }
	return Utils.Shuffle(randomList);
};

Utils.GetCardinalRadian = function (index_)
{
	return pi2 * index_ / 4;
};

Utils.GetRandomCardinalRadian = function () 
{ 
	return Utils.Segment(Math.random(), 4) * pi2; 
};

Utils.Rainbow = function (n) 
{
    n = n * 240 / 255;
    return 'hsl(' + n + ',100%,50%)';
};

// http://bocoup.com/weblog/find-the-closest-power-of-2-with-javascript/
Utils.NearestPow2 = function ( number ){
  return Math.pow( 2, Math.round( Math.log( number ) / Math.log( 2 ) ) ); 
};

// Stack overflow
Utils.Shuffle = function (array) 
{
  var currentIndex = array.length, temporaryValue, randomIndex;
  while (0 !== currentIndex) {
    randomIndex = Math.floor(Math.random() * currentIndex);
    currentIndex -= 1;
    temporaryValue = array[currentIndex];
    array[currentIndex] = array[randomIndex];
    array[randomIndex] = temporaryValue;
  }
  return array;
};

// https://github.com/gre/smoothstep
Utils.SmoothStep = function (min, max, value) {
	var x = Math.max(0, Math.min(1, (value-min)/(max-min)));
	return x*x*(3 - 2*x);
};

Utils.Clamp = function (value, min, max) {
	return Math.min(Math.max(value, min), max);
}

Utils.IsPointInCircle = function (center, radius, point) {
	dist = Math.sqrt(Math.pow((center.x - point.x), 2) + Math.pow((center.y - point.y), 2));
	return dist <= Math.pow(radius, 2);
}

/**
* parse query string
*/
Utils.getParameterByName = function (name) {
var match = RegExp('[?&]' + name + '=([^&]*)').exec(window.location.search);
return match && decodeURIComponent(match[1].replace(/\+/g, ' '));
}
Utils.Lerp = function (t, start, end) {
	return (end - start) * t + start;
};
