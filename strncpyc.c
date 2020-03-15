# include <stdio.h>

void strncpy_c(char *t, char *s, int n);
void strncat_c(char *t, char *s, int n);
int strncmp_c(char *t, char *s, int n);

int main()
{
    char start[] = "aaa";
    char end[] = "aaa";
    int n = 2;
    printf("%c", strncmp_c(end, start, n));
    return 0;
}

void strncpy_c(char *t, char *s, int n)
{
    int i = 0;
    while(i++ < n && (*s++ = *t++));
}

void strncat_c(char *t, char *s, int n)
{
    while(*s) s++;
    int i = 0;
    while(i++ < n && (*s++ = *t++));
}

int strncmp_c(char *t, char *s, int n)
{
    int i = 0;
    while(i++ < n && *s++ == *t++)
    {
        if (*(s-1) == '\0')
        {
            return 0;
        }
    }
    return *(s-1) = *(t-1);
}