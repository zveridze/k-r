// 3.3

# include <stdio.h>
# define MAXIMUM 1000

void expand(char s1[], char s2[]);

int main()
{
    char first[MAXIMUM] = "z-1";
    char second[MAXIMUM];
    expand(first, second);
    printf("%s\n", second);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i = 0;
    int j = 0;
    int len = 0;
    char temp[MAXIMUM];
    while(s1[i] != '\0')
    {
        if (s1[i] == '-'){

        }
        else
        {
            temp[j] = s1[i];
            ++j;
        }
        ++i;
    }
    int from, to;
    for (i = 0; i < j; ++i){
        from = temp[i];
        to = temp[i+1];
        while(from <= to)
        {
            s2[len] = from;
            ++len;
            ++from;
        }
    }
}