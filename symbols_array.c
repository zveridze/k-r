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

    max = 0;
    while ((len = line_getter(line, MAXLINE)) > 0)
    if (len > max)
    {
        max = len;
        copy(longest, line);
    }
    if (max > 0)
    {
        printf("%s", longest);
    }

    return 0;
}

int line_getter(char s[], int lim)
{
    int c, i;  
    // for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) /*Use this line instead next if you need infinite line.*/
    
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

void copy(char to[], char from[])
{
    int i = 0;
    while((to[i] = from[i]) != '\0')
    {
        ++i;
    }

}