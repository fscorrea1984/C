#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char **argv) {

	double d = 0.1;

	mpf_t f;
	mpf_init(f);
	mpq_t q;
	mpq_init(q);
	mpf_set_d(f,d);
	mpq_set_f(q,f);
	gmp_printf("%Qd\n",q);

	mpq_clear(q);
	mpf_clear(f);

	return 0;

}
