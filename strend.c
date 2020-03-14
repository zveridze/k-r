#include <stdio.h>

int cat(char *s, char *t);

int main()
{
    char start[] = "HelloWorld";
    char end[] = "World";
    printf("%d\n", cat(start, end));
    return 0;
}

int cat(char *s, char *t)
{
    int contains = 0;
    int i = 0;
    while(*s)
    s++;
    while(t[i] != '\0')
    i++;
    s = s - i;
    for (; *s != '\0' && *t != '\0'; s++, t++)
    {
        if (*s == *t)
        {
            contains = 1;   
        }
        else
        {
            contains = 0;
            break;
        }
    }
    return contains;
}