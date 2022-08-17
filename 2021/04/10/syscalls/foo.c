#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

	//extern char **environ;

	char *args[]={ "/usr/sbin/chroot","/","/bin/sh",NULL };

	execvp("/usr/sbin/chroot",args);

	return 0;

}
