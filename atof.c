# include <stdio.h>
# include <ctype.h>
# include <math.h>

float atof(char s[]);

int main()
{
    char line[] = "10.325e+3";
    printf("%f\n", atof(line));
    return 0;
}

float atof(char s[])
{
    double val, power, degval, exponent, base;
    int i;
    int sign, degsign;
    for (i = 0; (isspace(s[i])); i++) {}
    sign = (s[i] == '-') ? -1: 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (val = 0.0; (isdigit(s[i])); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
    }
    degsign = (s[i] == '-') ? -1: 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (degval = 0.0; isdigit(s[i]); i++)
    {
        degval = 10.0 * degval + (s[i] - '0');
    }

    exponent = pow(10.0, degval);
    base = sign * (val/power);

    return degsign == 1 ? base * exponent : base / exponent;
}