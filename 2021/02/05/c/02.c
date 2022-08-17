#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char **argv) {

	unsigned long l;
	double d = 10000000.0;

	mpf_t sr;
	mpf_init(sr);
	mpf_t df;
	mpf_init(df);
	mpf_set_d(df,d);
	//for(l = 1; l <= 10; l++) {
	mpf_sqrt(sr,df);
	gmp_printf("%.Ff\n",sr);
	//}

	mpf_clear(df);
	mpf_clear(sr);

	return 0;

}
