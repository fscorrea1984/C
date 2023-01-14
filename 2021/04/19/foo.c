#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *user;
char *host;
char *pass;

void *xmalloc (int size) {

	return(NULL);

}

char *mystrcpy(char *to, char *from) {

	char *save = to;

	while((*to = *from) != '\x00') {
		++from;
		++to;
	}

	return(save);

}

void *connect(char *h, char *u, char*p) {

	void *handle;

	host = xmalloc(strlen(h));
	user = xmalloc(strlen(u));
	pass = xmalloc(strlen(p));

	printf("Waiting for input\n");
	getchar();

	mystrcpy(host, h);
	mystrcpy(user, u);
	mystrcpy(pass, p);

	printf("Usage: connecting to the server %s, with username %s\n",host,user);
	
}

int main(int argc, char **argv) {

	void *handle;
	char buf[512];

	if(argc < 4) {
		printf("Usage: connect <host> <username> <password>\n");
		return 0;
	}

	handle = connect(argv[1],argv[2],argv[3]);
	
	printf("Connected.\n");

	while(1) {
		// accept the commands
		if(!fgets(buf,512,stdin))
			continue;
		printf("Processing the command %s\n",buf);
	}
	
	printf("Bye\n");
	
	return 0;
	
}
