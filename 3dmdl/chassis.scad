/**
 * Martin Wrms
 * 19.05.12
 * aurigaBot
 * chassis
 */
include<parameters.scad>;
include<rad.scad>;
include<motor.scad>;
include<pcb.scad>;

module motorholder() {
	union() {
		difference() {
			union() {
				translate([0, 0, 0])
				cylinder(h=7, r=3, $fn=res);

				translate([-3, -3, 0])
				cube([3,6,7]);
			}
			translate([0, 0, 1])
			cylinder(h=8, r=2.1, $fn=res);

			translate([0, 0, -0.5])
			cylinder(h=2, r=1.2, $fn=res);
		}
	}
}

module chassis() {
	union() {
		translate([10, 0, 11.5])
		motorholder();
		translate([-10, 0, 11.5])
		rotate([0,0,180])
		motorholder();
		difference() {
			union() {
				translate([-9,-3,-3])
				cube([18,6,9]);
			}
			translate([-12, 0, 0])
			rotate([0,90,0])
			cylinder(h=24, r=1.1, $fn=res);

			translate([0, 0, 1])
			cylinder(h=12, r=0.8, $fn=res, center=true);

			translate([5.5, 0, 1])
			cylinder(h=12, r=0.8, $fn=res, center=true);

			translate([-5.5, 0, 1])
			cylinder(h=12, r=0.8, $fn=res, center=true);

			translate([0,0,-1])
			cube([6, 8, 7], center=true);
		}
		translate([7,-3,6])
		cube([2,6,5.5]);

		translate([-9,-3,6])
		cube([2,6,5.5]);

		translate([5,-3,6])
		cube([2,1.5,12.5]);

		translate([5,1.5,6])
		cube([2,1.5,12.5]);

		translate([-7,-3,6])
		cube([2,1.5,12.5]);

		translate([-7,1.5,6])
		cube([2,1.5,12.5]);
	}
}

chassis();

/*
translate([0, 0, 4])
pcb();

translate([11.25, 0, 0])
rad();
translate([-11.25, 0, 0])
rotate([0,0,180])
rad();

translate([10, 0, 12])
motor();
translate([-10, 0, 12])
motor();
*/
