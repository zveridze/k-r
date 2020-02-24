# include <stdio.h>
# include <ctype.h>
# include "calc.h"


int getop(char s[])
{
    int p = 0;
    int i=0, c, t;
    static int last_c = 0;
    if (last_c == 0)
    {
        c = getch();
    }
    else
    {
        c = last_c;
        last_c = 0;
    }
    while((s[0] = c) == ' ' || c == '\t')
    {
        c = getch();
    }
    if (!isdigit(c) && c != '.')
    {
        if (c == '-')
        {
            if (isdigit(t = getch()) || t == '.')
            {
                c = t;
                s[++i] = c;
            }   
            else
            {
                ungetch(t);
                return c;
            }
        }
        else
        {
            return c;
        }
    }
    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.')
    {
        while(isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
}