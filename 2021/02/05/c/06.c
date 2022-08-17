#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <gmp.h>

int main(int argc, char **argv) {

//	double d = 0.1;
	double d = 23443.029392302;
//	int i;
//	double x = frexp(e,&i);
//	printf("%.16f %d\n",x,i);

//	return 0;

//	mpf_set_default_prec(512);
	mpf_t f;
	mpf_init(f);
	mpq_t q;
	mpq_init(q);
	mpf_set_d(f,d);
	mpq_set_f(q,f);
	mpq_canonicalize(q);
	mpz_t z;
	mpz_t num;
	mpz_t den;
	mpz_init(z);
	mpz_init(num);
	mpz_init(den);
	mpz_set(num,mpq_numref(q));
	mpz_set(den,mpq_denref(q));
	gmp_printf("%Zd %Zd %Qd\n",num,den,q);

	mpz_clear(den);
	mpz_clear(num);
	mpz_clear(z);
	mpq_clear(q);
	mpf_clear(f);

	return 0;

}
