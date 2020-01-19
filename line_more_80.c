# include <stdio.h>
#define MAXLINE 1000

int line_getter(char line[], int max);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = line_getter(line, MAXLINE)) > 0)
    {
        if (len > 80)
        {
            printf("%s", line);
        }
    }

    return 0;
}

int line_getter(char s[], int lim)
{
    int c, i;  
    
    for (i = 0; i <= lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}