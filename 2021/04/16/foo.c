#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

	char *lista[2];

	lista[0] = "/bin/sh";
	lista[1] = NULL;
	execve(lista[0],lista,NULL);

	exit(0);

}
