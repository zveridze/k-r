# include <stdio.h>
# include "calc.h"

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