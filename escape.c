# include <stdio.h>

# define MAXIMUM 4096

int form_string(char s[]);
void escape(char s[], char t[], int len);
void unscape(char s[], char t[], int len);


int main()
{
    char s[MAXIMUM];
    char t[MAXIMUM];
    char u[MAXIMUM];
    int len;
    len = form_string(s);
    escape(t, s, len);
    printf("%s\n", t);
}


int form_string(char s[])
{
    int i, c;

    for (i = 0; i <= MAXIMUM && (c = getchar()) != EOF && c != '\n'; ++i)
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


void escape(char to[], char from[], int len)
{
    int i = 0;
    int j = 0;
    while (from[i] != '\0' && i <= len)
    {
        switch(from[i])
        {
            case '\t': to[j++] = '\\'; to[j] = 't';
            break;
            case '\n': to[j++] = '\\'; to[j] = 'n';
            break;
            default:
            to[j] = from[i];
        }
        ++i;
        ++j;
    }
    to[j] = '\0';
}

void unscape(char to[], char from[], int len)
{
    // TODO: Don`t know what to do. Beacause C already interpretate '\t' as tab sybmol.
    int i = 0;
    while(from[i] != '\0')
    {
        switch(from[i])
        {
            case '\t': printf("%s\n", "A");
        }
        // switch(from[i])
        // {
        //     case '\\': printf("%s", "A");
        //     break;
        // }
        ++i;
    }
}