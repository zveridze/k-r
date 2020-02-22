# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void copy(void);
void swipe(void);
void clear(void);

int main()
{
    int type;
    double op2, op1;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
            push(atof(s));
            break;

            case '+':
            push(pop() + pop());
            break;

            case '*':
            push(pop() * pop());
            break;

            case '-':
            op2 = pop();
            push(pop() - op2);
            break;

            case 'p':
            op2 = pop();
            push(pow(pop(), op2));

            case 's':
            push(sin(pop()));

            case 'e':
            push(exp(pop()));

            case '?':
            peek();
            break;

            case '!':
            copy();
            break;

            case '$':
            swipe();
            break;

            case 'c':
            clear();
            break;

            case '%':
            op2 = pop();
            if (op2 != 0.0)
            {
                op1 = pop();
                push(op1 - op2 * floor(op1/op2));
            }
            else
            {
                printf("Ошибка деления на ноль");
            }
            break;

            case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("ошибка: деление на ноль\n");
            }
            break;

            case '\n':
            printf("“\t%.8g\n", pop());
            break;

            default:
            printf("ошибкаЖ неизвестная операция %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("ошибка: стек полон %g не помещается\n", f);
    }
}

double pop (void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("ошибка: стек пуст\n");
        return 0.0;
    }
}

double peek(void)
{
    double el = 0.0;
    if (sp > 0)
    {
        el = val[sp-1];
        return el;
    }
    else
    {
        printf("Ошибка: стэк пуст");
        return el;
    }
}

void copy(void)
{
    double new;
    if (sp > 0)
    {
        new = val[sp-1];
        push(new);
    }
}

void swipe(void)
{
    double temp;
    if (sp > 1)
    {
        temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
    }
}

void clear(void)
{
    if (sp > 0)
    {
        val[0] = '\0';
        sp = 0;
    }
    else
    {
        printf("Ошибка: стэк пуст");
    }
}

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int p = 0;
    int i=0, c, t;
    while((s[0] = c = getch()) == ' ' || c == '\t');
    // s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {
        if (c == '-')
        {
            if (isdigit(t = getch()) || t == '.')
            {
                c = t;
                s[++i] = c;
            }   
            else
            {
                ungetch(t);
                return c;
            }
        }
        else
        {
            return c;
        }
    }
    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.')
    {
        while(isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
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