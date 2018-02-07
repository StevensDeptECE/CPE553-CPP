#include <iostream>
#include <fstream>
using namespace std;
void stats(double x[], int n, double &mean, double &stdev, double& max, double& min) {
	// your code goes here!!!

}


int main() {
	ifstream f("grades.txt");
	double g;
	double array[256];
	while (!f.eof() ) {
		f >> g;
		cout << g << " ";
	}
	double mean, stddev, max, min;
	stats(array, n, mean, stddev, max, min);
	cout << mean << stddev << max << min;
}
	
