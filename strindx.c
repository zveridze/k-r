# include <stdio.h>

# define MAXIMUM 4096

int strindex(char s[], char t[]);

int main()
{
    char line[MAXIMUM] = "Hello, name! I love you wont you tell me your name.";
    char part[MAXIMUM] = "ame";
    printf("%d\n", strindex(line, part));
    return 0;
}

// Position of first entry
int strindex(char s[], char t[])
{
    int i;
    int j;
    int k;
    int max = 0;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        {
            if (i > max)
            {
                max = i;
            }
        }
    }
    return max;
}