/**
 * Martin Wrms
 * 19.05.12
 * aurigaBot
 * PCB
 */
include<parameters.scad>;

module pcb() {
	union() {
		color("DarkGreen")
		translate([0, 0, 16])
		cube([12, 1.5, 32], center=true);

		// A3901: h-bridge
		color("Black")
		translate([0, 1.1, 2])
		cube([3, 0.75, 3], center=true);

		// MSP430
		color("Black")
		translate([0, 1.3, 15])
		cube([7, 1, 7], center=true);

		// Gyro
		color("Black")
		translate([-3, 1.3, 8])
		cube([4, 1, 4], center=true);

		// Accelerometer
		color("Black")
		translate([3, 1.3, 8])
		cube([3, 1, 5], center=true);
		
		// Accu
		color("Silver")
		translate([0, -2.3, 15])
		cube([9, 3, 27], center=true);

		// additional stuff
		
	}
}
