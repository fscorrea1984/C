#include <stdio.h>
#include <string.h>
void func (int x, int y)
{
        double d;
        memcpy(&d,&x,sizeof(x));
        memcpy(((char*)&d)+4,&y,sizeof(y));
        printf("%lf\n", d);
}

int main(void)
{
        double d = 2.5;
        int x,y;
        memcpy(&x,&d, sizeof(x));
        memcpy(&y,((char*)&d)+4, sizeof(y));
        func(x,y);
        return 0;
}

