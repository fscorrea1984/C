#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char **argv) {

	double d = 0.1;

	mpq_t q;
	mpq_init(q);
	mpq_set_d(q,d);
	mpq_canonicalize(q);
	gmp_printf("%Qd\n",q);

	mpq_clear(q);

	return 0;

}
