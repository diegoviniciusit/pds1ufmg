#include <math.h>

float cauchy(float x) {
	return 1 / (M_PI * (1 + (x * x)));
}

float gumbel(float x, float mu, float beta) {
	float z = (x - mu) / beta;
	return (1 / beta) * exp(-1 * (z + exp(-1 * (z))));
}

float laplace(float x, float mu, float b) {
	float xmu = x - mu;
	if (xmu < 0) {
		xmu = -1 * xmu;
	}
	return 1 / (2 * b) * exp(-1 * (xmu) / b);
}
