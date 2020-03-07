# include <stdio.h>

// # define swap(t,x,y) {t temp = x; x = y; y = temp;}
# define swap(t,x,y) {t temp = x; x = y; y = temp;}

int main(void)
{
    int ai=1, bi=2;
    swap(int, ai, bi);
    printf("%i, %i\n", ai ,bi);
    return 0;
}