# include <stdio.h>

# define MAXIMUM 100

int write_line(char data[], int len);

int main()
{
    char data[MAXIMUM];
    write_line(data, MAXIMUM);
    printf("%s\n", data);
    return 0;
}

int write_line(char data[], int len)
{
    int c;
    int i = 0;
    while((c = getchar()) != EOF)
    {
        if (i > len)
        {
            break;
        }
        if (c == '\n')
        {
            break;
        }
        data[i] = c;
        i++;
    }
    return 0;
}