#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0; /* Нижняя граница температур */
    upper = 300; /* Верхняя граница температур*/
    step = 20; /* шаг */
    fahr = lower;
    printf("Таблица соответствия цельсий - фаренгейт.\n");
    while (fahr <= upper){
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}