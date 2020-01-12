# include <stdio.h>

int main()
{
    int c;
    while((c = getchar()) != EOF)
    {
        if (c == ' ')
            printf("\n");
        if (c != ' ')
            printf("%c", c);
    }
}