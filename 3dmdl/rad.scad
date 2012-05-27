/**
 * Martin Würms
 * 19.05.12
 * PicoBot
 * Rad
 */
include<parameters.scad>;

pneu_r1 = 9.0;
pneu_r2 = 2.0;

module pneu() {
	union(){
		rotate([0,90,0]) 
	   rotate_extrude()
  		translate([pneu_r1,0,0])
	   circle(r=pneu_r2-1, $fn=res);		
	}
}

module bearing() {
	union() {
		difference() {
			rotate(a=[0,90,0])
			translate([0,0,-1.5])
			cylinder(h=3, r=2.5, $fn=res);
			rotate(a=[0,90,0])
			translate([0,0,-2])
			cylinder(h=4, r=1.5, $fn=res);
		}
	}
}

module screw() {
	union() {
		rotate(a=[0,90,0])
		translate([0, 0,-4])
		cylinder(h=6, r=1.5, $fn=res);
		difference() {
			rotate(a=[0,90,0])
			translate([0,0,2])
			cylinder(h=2, r=3, $fn=res);
			translate([4,0,0])
			cube([2,1,8], center=true);
		}
	}
}
/*
module rad(all) {
	union(){
		difference() {
			rotate(a=[0,90,0])
			translate([0,0,-1])
			cylinder(h=2, r=8, $fn=res);
			// Achse
			rotate(a=[0,90,0])
			translate([0,0,-1.5])
			cylinder(h=3, r=2.55, $fn=res);
		}
	}
	if(all > 0) {
		pneu();
		bearing();
		screw();
	}
}
*/
//pneu();

module rad(all) {
	difference() {
		union(){
			rotate([0, 90, 0])
			rotate_extrude($fn=res) 
			polygon(points=[[2.55,-1], [3.5,-1], [3.5,-0.5], [8, -0.5], [8, -1], [9, -1], [9, -0.5], [8.5, 0], [9, 	0.5], [9, 1], [8, 1], [8, 0.5], [3.5,0.5], [3.5, 1], [2.55,1]]);
		}

		rotate(a=[0,90,0])
		translate([0,5.75,-1.5])
		cylinder(h=3, r=2, $fn=res);

		rotate(a=[0,90,0])
		translate([5.75,0,-1.5])
		cylinder(h=3, r=2, $fn=res);

		rotate(a=[0,90,0])
		translate([0,-5.75,-1.5])
		cylinder(h=3, r=2, $fn=res);

		rotate(a=[0,90,0])
		translate([-5.75,0,-1.5])
		cylinder(h=3, r=2, $fn=res);
	}
if(all > 0) {
		pneu();
		bearing();
		screw();
	}
}
