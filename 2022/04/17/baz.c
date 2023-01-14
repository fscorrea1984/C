void func(int x) {
        printf("%f\n", ((union {int i;float f;}){x}).f );
}
int main(void)
{
        func( ((union {int i;float f;}){.f=2.5}).i );
        return 0;
}
