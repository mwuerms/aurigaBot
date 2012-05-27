/**
 * Martin Würms
 * 19.05.12
 * PicoBot
 * chassis
 */
include<parameters.scad>;
include<rad.scad>;
include<motor.scad>;

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

			translate([0, 0, 0])
			cylinder(h=1, r=0.5, $fn=res);
		}
	}
}

module chassis() {
	union() {
		translate([9, 0, 11])
		motorholder();
		translate([-9, 0, 11])
		rotate([0,0,180])
		motorholder();
		difference() {
			union() {
				translate([-8,-3,-3])
				cube([16,6,7]);

/*
				translate([-8,-3,0])
				cube([16,6,4]);

				translate([-8,0,0])
				rotate([0, 90, 0])
				cylinder(h=16, r=3, $fn=res);
*/
			}
			translate([-12, 0, 0])
			rotate([0,90,0])
			cylinder(h=24, r=1.5, $fn=res);

			translate([0, 0, 0])
			cylinder(h=24, r=1.5, $fn=res, center=true);

			translate([4.5, 0, 0])
			cylinder(h=24, r=1.5, $fn=res, center=true);

			translate([-4.5, 0, 0])
			cylinder(h=24, r=1.5, $fn=res, center=true);
		}
		translate([6,-3,4])
		cube([2,6,7]);

		translate([-8,-3,4])
		cube([2,6,7]);

		translate([4,-3,4])
		cube([2,1.5,14]);

		translate([4,1.5,4])
		cube([2,1.5,14]);

		translate([-6,-3,4])
		cube([2,1.5,14]);

		translate([-6,1.5,4])
		cube([2,1.5,14]);
	}
}

chassis();

translate([10, 0, 0])
rad(1);
translate([-10, 0, 0])
rotate([0,0,180])
rad(1);


translate([9, 0, 12])
motor();
translate([-9, 0, 12])
motor();
