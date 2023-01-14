#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char **argv) {

	mpq_t a;
	mpq_init(a);
	mpq_set_str(a,"41/152",10);
	gmp_printf("the rational is: %Qd\n",a);
	mpq_clear(a);

	return 0;

}
