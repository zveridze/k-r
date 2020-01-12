# include <stdio.h>

int main()
{
    int c;
    int sybmols[40] = {0};
    while ((c = getchar()) != EOF)
    {
        sybmols[c]++;
        if (c == '0')
        {
            printf("Symbol frequency list:");
            for (int i = 0; i < 40; i++)
            {
                printf("%d: ", i);
                for (int y = 0; y < sybmols[i]; y++)
                {
                    printf("|");
                }
                printf("\n");
            }
        }
    }
    
}