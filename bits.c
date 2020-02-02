# include <stdio.h>

void printfbit(unsigned n);
int setbits(unsigned x, int p, int n, int y);
int invert(unsigned x, int p, int n, int y);
int rightrot(unsigned x, int n);

int main()
{
    // printf("%d\n", setbits(12, 3, 1, 4));
    printfbit(setbits(12, 3, 1, 4));
    // printfbit(12);
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
      return -x;
  }

int invert(unsigned x, int p, int n, int y)
  {
      int i;
      for (i=0; i <= n; ++i)
      {
          printfbit(x << i);
      }
      return 0;
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