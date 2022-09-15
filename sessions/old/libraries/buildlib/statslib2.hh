#pragma once

class Stats {
private:
	double min, max, sum, mean, var;
	uint32_t n;
public:
	static Stats var(const double x[], uint32_t n);
};
