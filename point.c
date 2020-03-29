# include <stdio.h>

struct point {int x; int y;};
struct rect {struct point p1; struct point p2;};
struct point makepoint(int x, int y);

int main()
{
    struct point first_point = {1, 2};
    struct point second_point = {3, 4};
    struct rect screen = {first_point, second_point};
    struct rect *cannonical;
    cannonical = &screen;
    printf("%d\n", cannonical->p1.x);
    screen.p1 = makepoint(5, 6);
    printf("%d\n", cannonical->p1.x);
    return 1;
}

struct point makepoint(int x, int y){
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}