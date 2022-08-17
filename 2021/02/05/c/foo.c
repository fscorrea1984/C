#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char **argv) {

	unsigned long l;

	mpf_t sr;
	mpf_init(sr);
	mpq_t rn;
	mpq_init(rn);
	for(l = 1; l <= 10000000; l++) {
		mpf_sqrt_ui(sr,l);
		mpq_set_f(rn,sr);
		//gmp_printf("%.Ff\n",sr);
	}

	gmp_printf("%Qd\n",rn);

	mpq_clear(rn);
	mpf_clear(sr);

	return 0;

}
