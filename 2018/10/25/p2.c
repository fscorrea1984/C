#include <stdio.h>
#include <stdlib.h>

enum days { SUN = -4 , MON , TUE , WED = 23 , THR , FRI , SAT };

typedef enum days e1_t;

int main(int argc, char **argv) {

  e1_t day;

  for(day = SUN; day <= SAT; day++)
    printf("%d\n", day);

  return 0;

}
