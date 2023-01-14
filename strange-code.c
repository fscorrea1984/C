#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
  unsigned long n = strtoul(argv[1],NULL,10), i = 0, j, c, sign; //apparently read a number from stdin
  char s[] = ""; //an empty C-string
  if((sign = n) < 0) //  (sign = n) < 0 first attributes n to sign, then tests if sign < 0
    n = -n; //if so, invert the sign ( -n = minus n)
  do {
    s[i++] = (char)n % 10 + '0'; // try to assign input n MOD 10 char-casted to some position of the C-string s[]
  } while((n /= 10) > 0); // divide n by 10 and repeat the former step until n/10 > 0
  if(sign < 0) // if sign < 0
    s[i++] = '-'; // Somewhere in the C-string assign the dash ('-') representing the "minus" sign of negative
  s[i] = '\0'; // null-terminate the C-string
  j = strlen(s); // retrieve its length
  for(i = 0, j = strlen(s)-1; i < j; i++, j--) { // set i = 0 and j to s[] length - 1
    c = s[i]; // c get the first char s[0]
    s[i] = s[j]; // s[0] get s[j]
    s[j] = (char)c; // and s[j] gets char-casted c
  } // it amounts to swapping s[i] and s[j], loop until i >= j
  puts(s); // print result
  return 0; // EXIT_SUCCESS
}
