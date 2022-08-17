#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {

	//unsigned long count = 0;

	double X = pow(10.0,7);

	//double x;

	//double y = sqrt(x);

	//printf("%.16f\n",y);

	for(double x = 1.0; x <= X; x++) {
		double y = sqrt(x);
		//count++;
		//printf("%.16f\n",y);
	}

	//printf("%lu\n",count);

	//printf("%.16f\n",x);

	return 0;

}
