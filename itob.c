// 3.5

#include <stdio.h>
#include <stdlib.h>
# define MAXIMUM 4096

void inob(int n, char s[], int b);

int main()
{
    int number = 1135;
    char new_line[MAXIMUM];
    int base = 16;
    inob(number, new_line, base);
    return 0;
}

void inob(int n, char s[], int b)
{
    char digits[] = "0123456789ABCDEF";
    int i = 0;
    do
    {
        s[i] = digits[n % 16];
        n = n / 16;
        ++i;
    } while (n > 0);
    s[i] = '\0';

    // reverse array
    char temp[MAXIMUM];
    int j = 0;
    while (i >= 0)
    {
        temp[j] = s[i-1];
        ++j;
        --i;
    }
}