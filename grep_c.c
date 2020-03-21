# include <stdio.h>
# include <string.h>

# define MAXLINE 1000

int getl(char *line, int max);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;
    if (argc != 2)
    {
        printf("Используйте в find образец");
    }
    else
    {
        while(getl(line, MAXLINE) > 0)
        {
            if(strstr(line, argv[1]))
            {
                printf("%s", line);
                found++;
            }
            printf("%d\n", found);
        }    
    }
    return found;
}


 int getl(char *ps, int lim)
 {
     int c;
     char *start = ps;

     while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
         *ps++ = c;
     if (c == '\n')
         *ps++ = c;
     *ps = '\0';
     return ps-- - start;
 }