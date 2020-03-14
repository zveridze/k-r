#include <stdio.h>

void cat(char *s, char *t);

int main()
{
    char start[] = "Hello";
    char end[] = "World";
    cat(start, end);
    printf("%s\n", start);
    return 0;
}

void cat(char *s, char *t)
{
    while(*s)
    s++;
    while((*s++ = *t++));
}