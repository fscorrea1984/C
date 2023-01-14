#include <stdio.h>
#include <stdlib.h>

void inutil()
{
    puts("Como foi que cheguei aqui?");
    exit(1);
}

void util()
{
  void (*nada)() = &inutil;
  nada = inutil;
  nada();
}

int main(int argc, char **argv)
{
    util();
    return 0;
}
