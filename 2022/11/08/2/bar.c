#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person_t {
  char name[32];
  unsigned int age;
  char sex;
};

typedef struct person_t person;

int main(int argc, char **argv) {
  person p = {.name = "Will", .age = 18, .sex = 'M' };
  printf("%s\n",p.name);
}
