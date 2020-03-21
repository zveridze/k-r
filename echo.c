# include <stdio.h>


// First version
// int main(int argc, char *argv[])
// {
//     int i;
//     for (i = 0; i < argc; i++)
//     {
//         printf("%s", argv[i]);
//     }
//     printf("\n");
//     return 0;
// }


// Second version
int main(int argc, char *argv[])
{
    while(--argc > 0)
    {
        printf("%s%s", *argv, (argc > 1)? " ": "");
    }
    printf("\n");
    return 0;
}