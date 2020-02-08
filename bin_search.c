# include <stdio.h>

int bin_search(int x, int v[], int n);
int bin_search_2(int x, int v[], int n);

int main()
{
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    printf("%i\n", bin_search(5, a, 10));
    printf("%i\n", bin_search_2(5, a, 10));
    return 0;
}

int bin_search(int x, int v[], int n)
{
    int low = 0;
    int hight = n - 1;
    int mid;
    while (low <= hight)
    {
        mid = (low + hight) / 2;
        if (x < v[mid])
        {
            hight = mid -1;
        }
        else if (x > v[mid])
        {
            low = mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int bin_search_2(int x, int v[], int n)
{
    int low = 0;
    int hight = n - 1;
    int mid = (low + hight) / 2;
    while (low <= hight && x != v[mid])
    {
        if (x < v[mid])
        {
            hight = mid-1;
        }
        else
        {
            low = mid+1;
        }
        mid = (low + hight) / 2;
    }
    if (x == v[mid]){
        return mid;
    }
    return -1;
    
}