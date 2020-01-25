# include <stdio.h>

# define tab 4

int detab(char data[]);
int entab(char data[]);

int main()
{
    char line[100];
    int len;

    // while ((len = detab(line)) > 0)
    // {
    //     printf("%s\n", line);
    // }
    // int x = 5 % 3;
    // printf("%d\n", x);
    while((len = entab(line)) > 0)
    {
        printf("%s\n", line);
    }

    return 0;
}

int entab(char data[])
{
    int i, c, counter;
    char prev;
    counter = 0;
    for (i= 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (c == ' ')
        {
            counter++;
        }
        if (counter == 4)
        {
            printf("%s", "\t");
            counter = 0;
        }
        if (c != ' ')
        {
            while (counter > 0)
            {
                printf("%c", ' ');
                counter--;
            }
            printf("%c", c);
        }
    }
    return i;
}


int detab(char data[])
{
    int c, i, y;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (c == '\t')
        {
            for (y=i; y <= i+tab; ++y)
            {
                data[y] = ' ';
            }
            i = i + tab;
        }
        else
        {
            data[i] = c;
        }
    }
    return i;
}
