#include <stdio.h>

int lower(char upper);

int main()
{
    char c;
    while((c = getchar()) != EOF)
    {
        printf("%c", lower(c));
    }
    return 0;
}

int lower(char upper)
{
    return upper >= 'A' && upper <= 'Z' ? upper + 'a'-'A' : upper;
}