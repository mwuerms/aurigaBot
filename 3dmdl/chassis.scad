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
		translate([11, 0, 11.5])
		motorholder();
		translate([-11, 0, 11.5])
		rotate([0,0,180])
		motorholder();
		difference() {
			union() {
				translate([-10,-3,-3])
				cube([20,6,9]);
			}
			translate([-12, 0, 0])
			rotate([0,90,0])
			cylinder(h=24, r=1.1, $fn=res);

			translate([0, 0, 1])
			cylinder(h=12, r=0.8, $fn=res, center=true);

			translate([6.5, 0, 1])
			cylinder(h=12, r=0.8, $fn=res, center=true);

			translate([-6.5, 0, 1])
			cylinder(h=12, r=0.8, $fn=res, center=true);

			translate([0,0,-1])
			cube([6, 8, 7], center=true);
		}
		translate([8,-3,6])
		cube([2,6,5.5]);

		translate([-10,-3,6])
		cube([2,6,5.5]);

		translate([6,-3,6])
		cube([2,1.5,12.5]);

		translate([-8,-3,6])
		cube([2,1.5,12.5]);
	}
}

chassis();
