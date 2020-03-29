# include <stdio.h>
# include <string.h>

# define MAXLINE 1000

int getl(char *line, int max);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int lineno = 0;
    int found = 0;
    int except = 0;
    int number = 0;
    int c;
    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while ((c = *++argv[0]))
        {
            switch(c)
            {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: неверный параметр %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }
    if (argc != 1)
    {
        printf("Используйте: find -x -n \"образец\"\n");
    }
    else
    {
        while(getl(line, MAXLINE) > 0)
        {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except)
            {
                if (number)
                {
                    printf("%d", lineno);
                }
                printf("%s", line);
                found ++;
            }
        }
        return found;
    }
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