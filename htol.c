#include <stdio.h>
#include <ctype.h>

#define MAXIMUM 1000

int htol(char data[]);
int hex_to_dec(char hex);

int main()
{
    int len;
    char data[] = "0xb5A\0";
    printf("%i\n", htol(data));
    return 0;
}

int htol(char data[])
{
    int i = 0;
    int valid = 1;
    int result = 0;
    if (data[i] == '0')
    {
        ++i;
        if (data[i] == 'X' || data[i] == 'x')
        {
            i++;
        }
        else
        {
            valid = 0;
        }
    }
    else
    {
        valid = 0;
    }
    while (valid && data[i] != '\0')
    {
        result += hex_to_dec(data[i]);
        i++;
    }
    return result;
}

int hex_to_dec(char hex)
{
    int result = 0;
    int i;
    char valid[] = "abcdef";
    char lower_hex;
    if (isdigit(hex))
    {
        result += (int)hex-48;
    }
    else
    {
        if (hex >= 'A' && hex <= 'Z')
            {
                hex = hex + 'a' - 'A';
            }
        for (i = 0; i <= 5; ++i)
        {
            if (valid[i] == hex)
            {
                result += (i + 10);
            }
        }
    }
    i = 0;
    return result;
}
