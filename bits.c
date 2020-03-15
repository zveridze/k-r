# include <stdio.h>

// 10+1-2

void printfbit(unsigned n);
int setbits(unsigned x, int p, int n, int y);
int invert(unsigned x, int p, int n, int y);
int rightrot(unsigned x, int n);

int main()
{
    // printfbit(setbits(79, 5, 2, 7));
    printfbit(invert(11, 1, 2, 4));
    return 0;
}

void printfbit(unsigned n)
  {
      int i;
      for(i = 7; i >= 0; --i) {
          printf("%d", (n >> i) & 1);
      }
      printf("\n");
  }

int setbits(unsigned x, int p, int n, int y)
  {
    return x | (~(~0 << n) & y) << (p+1-n);
  }

int invert(unsigned x, int p, int n, int y)
  {
      return x;
  }

int rightrot(unsigned x, int n)
  {
      int i;
      for (i=1; i <= n; ++i)
      {
          x = x << i;
      }
    return x;
  }