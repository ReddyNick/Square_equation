

//зачем указатели вместо ссылок

#include <stdio.h>
#include <math.h>
#include <assert.h>
 

// if number of roots is infinite
#define INF_ROOTS 3 

// solve a linear equation
int SolveLin(double b, double c, double *x);

// solve a square equation
int SolveSq(double a, double b, double c, double *x1, double *x2);


int SolveLin(double b, double c, double *x) {
	if (b == 0)
		if (c == 0)
			return INF_ROOTS;
		else
			return 0;
	else {
			*x = -c / b;
			return 1;
	}
}
int SolveSq(double a, double b, double c, double *x1, double *x2) {

	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));

	assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);

	if (a == 0)
		return SolveLin(b, c, x1); //if equation is linear
	else {
		// D - discriminant
		double D = b * b - 4 * a*c;

		if (D < 0)
			return 0;
		if (D == 0) {
			*x1 = -b / (2 * a);
			return 1;
		}
			*x1 = (-b - sqrt(D)) / (2 * a);
			*x2 = (-b + sqrt(D)) / (2 * a);
			return 2;
	}
}

int main(){
	
	printf("Enter a, b, c:\n");
	
	// coefficients of the equation
	double a = 0, b = 0, c = 0;
	scanf("%lg %lg %lg", &a, &b, &c);

	// roots of the equation
	double x1 = 0, x2 = 0;

	// number of roots
	int nroots = SolveSq(a, b, c, &x1, &x2);

	switch (nroots) {
		case 0:  printf("No roots no fruits \n");
				 break;

		case 1:  printf("x = %lg \n", x1);
				 break;

		case 2:  printf("x1 = %lg \n", x1);
				 printf("x2 = %lg \n", x2);
				 break;

		case INF_ROOTS:
				 printf("any number \n");
				 break;

		default: printf("main(): ERROR: nroots = %d\n", nroots);
				 return 1;
	}
	return 0;
}