#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <gmp.h>
#include <math.h>

int main(int argc, char **argv) {

	double d = 2.3;
	int i;

	double x = frexp(d,&i);

	printf("%.16f\n",x);
	printf("%.16f %d\n",d,i);

	return 0;

}
