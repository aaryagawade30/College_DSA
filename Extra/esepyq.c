#include <stdio.h>

int main()
{
    struct paint {
        int type;
        int col;
    }p1, p2, *p3;
    p3 = &p1;
    p3->type = 1;
    p3->col = 5;
    p2.type = 22;
    p2.col = 56;

    if(sizeof(p3) == sizeof(p2)) {
        printf("Same");
    }
    else {
        printf("Different");
    }

    return 0;
}