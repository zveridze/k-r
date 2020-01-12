# include <stdio.h>

float fahr_to_cel(float fahr);

int main()
{
    int i, upper, lower, step;
    float cel;
    step = 20;
    lower = -20;
    upper = 300;
    for (i = lower; i <= upper; i=i+step)
    {
        cel = fahr_to_cel(i);
        printf("%3d %6.1f\n", i, cel);
    }
}

float fahr_to_cel(float fahr)
{
    float cel;
    cel = (5.0/9.0) * (fahr-32.0);
    return cel;
}