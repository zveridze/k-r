# include <stdio.h>
# include <limits.h>
# include <float.h>

int main()
{
    printf("The number of bits in a byte %d\n", CHAR_BIT);

    printf("The minimum value of CHAR = %d\n", CHAR_MIN);
    printf("The maximum value of CHAR = %d\n", CHAR_MAX);
    printf("The maximum value of CHAR = %d\n", UCHAR_MAX);
    printf("The minimum value of SHORT = %d\n", SHRT_MIN);
    printf("The maximum value of SHORT = %d\n", SHRT_MAX);
    printf("The maximum value of SHORT = %d\n", USHRT_MAX);
    printf("The minimum value of INT = %i\n", INT_MIN);
    printf("The maximum value of INT = %i\n", INT_MAX);
    printf("The maximum value of INT = %u\n", UINT_MAX);
    printf("The minimum value of LONG = %li\n", LONG_MIN);
    printf("The maximum value of LONG = %li\n", LONG_MAX);
    printf("The maximum value of UNSIGNED LONG = %lu\n", ULONG_MAX);

    printf("The maximum value of float = %.10e\n", FLT_MAX);
    printf("The maximum value of float = %.10e\n", FLT_MIN);
    return 0;
}