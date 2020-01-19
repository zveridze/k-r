# include <stdio.h>

# define MAXIMUM 1000


int line_getter(char line[], int max);
void revers_string(char originl[], char reversed[], int items);

int main()
{
    char line[MAXIMUM];
    char reversed[MAXIMUM];
    int len;

    while ((len = line_getter(line, MAXIMUM)) > 0)
    {
        revers_string(line, reversed, len);
        printf("%s\n", reversed);
    }

    return 0;
}

int line_getter(char line[], int max)
{
    int i, c;

    for (i = 0; i <= max-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void revers_string(char original[], char reversed[], int items)
{
    int i = 0;
    while((reversed[i] = original[items-2-i]) != '\0')
    {
        ++i;
    }
    
}