# include <stdio.h>
# include <string.h>


# define MAXLINES 5000
# define STRINGSLEN 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int rigth);

int main()
{
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("Ошибка! Слишком много строк!");
        return 1;
    }
}

#define MAXLEN 1000

int getshit(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
    char string[STRINGSLEN];
    int len, nlines;
    char *p;
    char line[MAXLEN];
    nlines = 0;

    while ((len = getshit(line, MAXLEN)) > 0)
    {
        p = string + strlen(string);
        if (nlines >= maxlines || len + strlen(string) >= STRINGSLEN)
        {
            return -1;
        }
        else
        {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
    {
        printf("%s\n", *lineptr++);
    }
}


void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right)
    {
        return;
    }

    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
        swap(v, last, last);
        qsort(v, left, last-1);
        qsort(v, last+1, right);
    }
}

void swap(char *v[], int i, int j)
{
    char * temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}