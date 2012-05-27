/**
 * Martin Würms
 * 19.05.12
 * PicoBot
 * Rad
 */
include<parameters.scad>;

module motor() {
	union() {
		cylinder(h=7,r=2, $fn=res);
		translate([0,0,-0.5])
		cylinder(h=0.5,r=1.5, $fn=res);
		translate([0,0,-3.5])
		cylinder(h=3,r=0.25, $fn=res);
	}
}
