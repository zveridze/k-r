# include <stdio.h>

# define MAXIMUM 10000

int comments(char data[]);
void decoment(char data[], int len);

int main()
{
    int len, c;
    char data[MAXIMUM];
    while((c = comments(data)) != 0)
    {
        decoment(data, c);
    }
    return 0;
}

int comments(char data[])
{
    int i, c;
    int line;
    int star;
    for (i = 0; (c = getchar()) != EOF && i < MAXIMUM; ++i)
    {
        data[i] = c;
    }
    return i;
}

void decoment(char data[], int len)
{
    int i;
    int comment = 0;
    int quotes = 0;
    for (i = 0; i < len; ++i)
    {
        if (data[i] == '\"' || data[i] == '\'')
        {
            quotes = 1;
        }
        if (data[i] == '/' && data[i+1] == '*' && !quotes)
        {
            comment = 1;
        }
        if (comment && data[i-2] == '*' && data[i-1] == '/')
        {
            comment = 0;
        }
        if (!comment)
        {
            printf("%c", data[i]);
        }        
    }
}