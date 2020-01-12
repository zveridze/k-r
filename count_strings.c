# include <stdio.h>

int main()
{
    int c, nl, tab, space;
    nl = 0;
    tab = 0;
    space = 0;
    while ((c=getchar()) != EOF)
    {
        if (c == '\n')
            nl++;
        if (c == '\t')
            tab++;
        if (c == ' ')
            space++;
    }
    printf("New lines: %d\n", nl);
    printf("Tabs: %d\n", tab);
    printf("Spaces: %d\n", space);
}