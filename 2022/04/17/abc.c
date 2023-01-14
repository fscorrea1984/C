#include <stdio.h>
#include <string.h>
union abc_u {
        int i;
        float f;
};

void func(int x) {
        union abc_u abc;
        abc.i = x;
        printf("%f\n", abc.f);
}

int main(void)
{
        union abc_u abc;
        abc.f = 2.5;
        func(abc.i);
        return 0;
}
