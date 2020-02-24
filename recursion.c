# include <stdio.h>
# include <string.h>

# define MAXIMUM 4096

void atoi(int number, char number_string[]);
void reverse(char float_string[], int first, int last);

int main()
{
    int number = 1020;
    char number_string[MAXIMUM];
    atoi(number, number_string);
    printf("%s\n", number_string);
    reverse(number_string, 0, strlen(number_string)-1);
    printf("%s\n", number_string);
}

void atoi(int number, char number_string[])
{
    static int i;
    if (number != 0)
    {
        number_string[i] = number % 10 + '0';
        i++;
        atoi(number / 10, number_string);
    }
    else
    {
        number_string[i] = '\0';
    }
}

void reverse(char float_string[], int first, int last)
{
    int c;
    c = float_string[first];
    float_string[first++] = float_string[last];
    float_string[last--] = c;

    if (first <= last)
    {
        reverse(float_string, first, last);
    }
}