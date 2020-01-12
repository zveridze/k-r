# include <stdio.h>

int main()
{
    int c;
    int prev;
    while((c = getchar()) != EOF)
    {
        if (c == ' ' && prev == ' ')
        ;
        if (c == ' ' && prev != ' ')
            printf("%c", c);
        if (c != ' ')
            printf("%c", c);
        prev = c;
    }
}
