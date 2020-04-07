# include <stdio.h>
# include <ctype.h>
# include <string.h>


// char *word[] = {"abc", "def"};
// printf("%s  %c\n", word[0], *word[0]);
// char *x = word;
// *x++ = 'x';
// printf("%s %c\n", word[1], word[0]);

int main(int argc, char *argv[])
{
    int c;
    while((c = getchar()) != EOF)
    {
        if(isspace(c))
        {
            printf("!@#");
        }
    }
    return 0;
}