#include <iostream>
#include <fstream>
using namespace std;

// compute the average of the elements in x and return
double average(const double x[], int n) {

}
//https://en.wikipedia.org/wiki/Standard_deviation
// divide by n not n-1, grades are not a sample, they are everyone's grades.
void stats(const double x[], int n, double& mean, double& stdev, double& max, double& min) {
	// your code goes here!!!

  min = ??
  max = ??
  mean = ???
  stdev = ???
}


int main() {
	ifstream f("grades2.txt");
	double temp;
	// read in n from the file
	double array[n];
	while (!f.eof() ) {
		f >> temp;
		cout << temp << " ";
		// add the numbers to your array
	}
	cout << average(array, n) << '\n';
	double mean, stddev, max, min;
	stats(array, n, mean, stddev, max, min);
	cout << mean << " " << stddev << " " << max << " " << min;
}
	
