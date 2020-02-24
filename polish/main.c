# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <math.h>
# include "calc.h"

#define MAXOP 100

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
