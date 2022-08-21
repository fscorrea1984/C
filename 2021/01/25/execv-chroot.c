#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

	char *args[] = {"/usr/sbin/chroot","/",(char *)0};

	//int ret = execve(args[0], args, NULL);
	int ret = execvp("/usr/sbin/chroot", args);

	return 0;

}
