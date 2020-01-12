# include <stdio.h>

int main()
    {
 
        int ndigit[10] = {0};
        int i, c;
        int length = 0;
 
        while((c = getchar()) != EOF)
        {
            if (c == '0')
            {
                printf("Frequently words length\n");
                for (i = 0; i < 10; i++)
                {
                    printf("%d:", i);
                    for (int y = 0; y < ndigit[i]; y++)
                    {
                        printf("%c", '|');
                    }
                    printf("\n");
                }
            }
            if (c != ' ' && c != '\t' && c != '\n')
            {
                length++;
            }
            else
            {
                ndigit[length]++;
                length = 0;
            }
            
        }
    }