#include <stdio.h>
#include <string.h>
union gay_u {
        int i;
        float f;
};

void func(int x) {
        union gay_u gay;
        gay.i = x;
        printf("%f\n", gay.f);
}

int main(void)
{
        union gay_u gay;
        gay.f = 2.5;
        func(gay.i);
        return 0;
}
