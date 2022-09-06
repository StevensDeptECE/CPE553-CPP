#include <iostream>
#include <fstream>
using namespace std;
// mean = average sum(all elements) / n
// std dev = https://en.wikipedia.org/wiki/Standard_deviation (you may divide by n, not n-1)
void stats(double x[], int n, double &mean, double &stdev, double& max, double& min) {
	// your code goes here!!!

}


int main() {
	ifstream f("grades.txt");
	double g;
	double array[256];
	int n;
	while (!f.eof() ) {
		f >> g;
		cout << g << " ";
	}
	double mean, stddev, max, min;
	stats(array, n, mean, stddev, max, min);
	cout << mean << stddev << max << min;
}
	
