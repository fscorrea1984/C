#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long int wcount;

void rwfiles(FILE *fh1,FILE *fh2) {

	unsigned char s[1];
	memset(s,'\x00',1);

	fread(s,1,1,fh1);

	while (s[0] != '\x0A') {
	
		//if('\x1F' <= s[0] <= '\x7F') {
		if(('\x1F' >= s[0]) && (s[0] <= '\x7F')) {
		fread(s,1,1,fh1);
		continue;
		}

		if(s[0] == '\x20') wcount++;
		
		fwrite(s,1,1,fh2);
	
		fread(s,1,1,fh1);

	}

}


int main (int argc, char **argv) {

	FILE *fh1;
	FILE *fh2;

	fh1 = fopen("foo.txt","rb");
	fh2 = fopen("foo.bin","wb");

	if ((fh1 <= 0) || (fh2 <= 0)) {
		perror("Error Opening File");
		abort();
	}

	rwfiles(fh1,fh2);
	char c = '\x0A';
	fwrite(&c,1,1,fh2);

	fclose(fh2);
	fclose(fh1);

	return 0;

}
