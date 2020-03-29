# include <stdio.h>
# include <ctype.h>
# include <string.h>

# define MAXWORD 100

struct key {char *word; int count;};
struct key keytab[] = {
     "_asm", 0,
     "as_m", 0,
     "asm", 0,
     "break", 0,
     "case", 0,
     "char", 0
 };

# define NKEYS (sizeof keytab / sizeof keytab[0])

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main()
{
    int n;
    char word[MAXWORD];

    while(getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
            {
                keytab[n].count++;
            }
        }
    }
    for (n = 0; n < NKEYS; n++)
    {
        if (keytab[n].count > 0)
        {
            printf("%d %s\n", keytab[n].count, keytab[n].word);
        }
    }
    return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
        {
            high = mid -1;
        }
        else if (cond > 0)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int getword(char *word, int lim)
{
    int c, t, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()));
    if (c != EOF)
    {
        *w++ = c;
    }
    if (!isalpha(c))
    {
        *w = '\0';
    }
    if (isalpha(c) || c == '_')
        for (; --lim > 0; w++)
        {
            if(!isalpha(*w = getch()) && *w != '_')
            {
                ungetch(*w);
                break;
            }
        }
    else if(c == '"')
    {
        while((t = getch()) != c && t != EOF);
    }
    else if (c == '/')
    {
        if ((t = getch()) == '*')
        {
            while((t = getch()) != EOF)
            {
                if (t == '*')
                {
                    if ((t = getch()) == '/')
                    {
                        break;
                    }
                    else
                    {
                        ungetch(t);
                    }
                }
            }
        }
        else
        {
            ungetch(t);
        }
    }
    *w = '\0';
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