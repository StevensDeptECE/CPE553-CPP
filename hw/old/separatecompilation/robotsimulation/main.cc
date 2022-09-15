#include "robot.hh"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
vector<robot> robots;

void read_robots() {
	ifstream f("robots.dat"); // open text file with locations of robots
	char buffer[1024]; // max we can handle is 1024 character on a line
	f.get(buffer, sizeof(buffer));
	istringstream line(buffer);
	line >> num_robots; // read in the number of robots from the first line
	for (uint32_t i = 0; i < num_robots; i++) {
		f.get(buffer, sizeof(buffer));
		istringstream line(buffer);
		robots.push_back(robot(line)); // read in each robot from a line
	}
}

void print_robots() {
	// implement this function to print out the state of each robot
}


void draw_robots() {
	// create a text file which can be plotted in MATLAB or Octave
	ofstream draw("robot_locations.dat");

	// output should be n lines of output each containing:
	   x y heading
}

int main() {
	read_robots();
	print_robots();
	draw_robots();
}
