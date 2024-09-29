#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
double sin_series(double x, double eps);
double sin2x(double sinx);
double sin_my(double x, double eps);

int main(void) {
	double x = 0, eps = 0;
	while (1) {
		printf("Enter point:\n");
		if (scanf("%lf", &x) < 1) {
			break;
		}
		printf("\nEnter accuracy:\n");
		if (scanf("%lf", &eps) < 1) {
			break;
		}
		printf("\nMy answer: %.12lf\nRight answer: %.12lf\n", sin_my(x, eps), sin(x));
	}
	return 0;
}

double sin_series(double x, double eps) {
	double sum = 0,	x_n = 0; int n = 0;
	
	n = 0;
	x_n = x;
	sum = 0;
	while (fabs(x_n) > eps) {
		sum += x_n;
		x_n *= x*x*(-1)/(2*(n+1)*(2*n+3));
		n++;
	}

	return sum;
}

double sin2x(double sinx) {
	double sign = 0;
	if (sinx > 0) {
		sign = 1;
	} else if (sinx < 0) {
		sign = -1;
	} else {
		sign = 0;
	}

	return sign*sqrt(1- (1-2*sinx*sinx)*(1-2*sinx*sinx));
}

double sin_my(double x, double eps) {
	while ( x > PI) {
		x -= 2*PI;
	}
	while (x < (-1)*PI) {
		x += 2*PI;
	}

	if (fabs(x) < 1) {
		return sin_series(x, eps);
	}
	
	return sin2x(sin_my(x/2, eps));
}
