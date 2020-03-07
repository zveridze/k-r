# include <stdio.h>
# include <ctype.h>

int getch(void);
void ungetch(int c);
int getint(int *pn);

int main()
{
    int i, type, array[1024], getint(int *);

    for (i = 0; i < 1024 && (type = getint(&array[i])) != EOF; i++)
        printf("array[%d] = %d %s\n", i, type ? array[i] : type,
               type ? "" : "is not a number");
    return 0;
}

int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        return 0;
    }
    sign = (c == '-')? -1: 1;
    if (c == '+' || c == '-')
    {
        c = getch();
        if (!isdigit(c)) 
        {
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}


# define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: слишком много символов\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}