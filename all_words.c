# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

#define MAXWORD 100

struct tnode{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *rigth;
};

struct tnode *addtree(struct tnode *, char*, int count);
void treeprint(struct tnode *);
int getword(char *, int);

int main(int argc, char *argv[])
{
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    int count = 3;
    if (argc > 1)
    {
        count = atoi(argv[1]);
    }
    while (getword(word, MAXWORD) != NULL)
    {
        if (isalpha(word[0]))
        {
            root = addtree(root, word, count);
        }
        treeprint(root);
    }
    return 0;
}

struct tnode *talloc(void);
char *strdups(char *);

struct tnode *addtree(struct tnode *p, char *w, int count)
{
    int cond;
    if (p == NULL)
    {
        p = talloc();
        p->word = strdups(w);
        p->count = 1;
        p->left = p->rigth = NULL;
    }
    else if ((cond = strncmp(w, p->word, count)) == 0)
    {
        p->count++;
    }
    else if (cond < 0)
    {
        p->left = addtree(p->left, w, count);
    }
    else
    {
        p->rigth = addtree(p->rigth, w, count);
    }
    return p;
}

void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint (p->left);
        printf("%4d   %s\n", p->count, p->word);
        treeprint (p->rigth);
    }
}

struct tnode *talloc(void)
{
    return (struct tnod *) malloc(sizeof(struct tnode));
}

char *strdups(char *s)
{
    char *p;
    p = (char *) malloc(strlen(s)+1);
    if (p != NULL)
    {
        strcpy(p, s);
    }
    return p;
}

int getword(char *word, int lim)
{
    int c, t, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()));
    if (c != EOF)
    {
        *w++ = c;
    }
    if (isalpha(c) || c == '_')
        for (; --lim > 0; w++)
        {
            if(!isalnum(*w = getch()) && *w != '_')
            {
                ungetch(*w);
                break;
            }
        }
    else if(c == '"')
    {
        while((t = getch()) != c && t != EOF);
    }
    else if (c == '/')
    {
        if ((t = getch()) == '*')
        {
            while((t = getch()) != EOF)
            {
                if (t == '*')
                {
                    if ((t = getch()) == '/')
                    {
                        break;
                    }
                    else
                    {
                        ungetch(t);
                    }
                }
            }
        }
        else
        {
            ungetch(t);
        }
    }
    *w = '\0';
    return c;
}

# define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: слишком много символов\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}