# include <stdio.h>

# define LENGTH 10

int line(char data[]);

int main()
{
    int result;
    char data[100];
    while((result = line(data)) > 0)
    {
        printf("%s\n", data);
    }
    return 0;
}

int line(char data[])
{
    int i, c;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (i > 0 && (i % LENGTH) == 0)
        {
            data[i] = '\n';
            i++;
        }
        data[i] = c;
    }
    return i;
}
