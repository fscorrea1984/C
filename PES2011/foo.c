#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    
    FILE *fp = fopen("foo.txt","r");
    int c;
    
    while((c = fgetc(fp)) != EOF) {
        if (islower(c))
            c=toupper(c);
        putchar(c);
    }
    
    fclose(fp);
    
    return 0;
    
}