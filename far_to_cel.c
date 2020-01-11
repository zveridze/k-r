# include <stdio.h>

int main()
{
    float celsius, fahr;
    int lower, upper, step;
    printf("Таблица соответствия фаренгейт и цельсия\n");
    lower = -20;
    upper = 150;
    step = 10;
    fahr = lower;
    while(fahr <= upper){
        printf("%3.0f%8.1f\n", fahr, fahr-32 * (5.0/9.0));
        fahr = fahr + step;
    }
    return 0;
}