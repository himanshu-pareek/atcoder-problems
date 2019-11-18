// #define big(a, b) a > b ? a : b
#include <stdio.h>
int main() {
    // printf ("%d", big (5, 3));
    // char x;
    // for (x = 1; x <= 10; x++)
    //     printf ("%d", x);
    // int a = 1;
    // if (a--)
    // printf ("TRUE");
    // if (a++)
    // printf ("FALSE");
    // int i = 0;
    // int j = i++ + i;
    // printf ("%d", j);
    // int i = 10, *p = &i;
    // foo (p++);
    // float var[10][20];
    // var[5][3] = 746;
    // printf ("%f %f", *(*(var + 5) + 3), *(var[5] + 3));
    int x = 10;
    int *p;
    int **q;
    int ***r;
    p = &x;
    q = &p;
    r = &q;
}
void foo (int * p) {
    printf ("%d\n", *p);
}