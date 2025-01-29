#include <stdio.h>

struct poly
{
    int coef;
    int expo;
};

struct poly p1[10], p2[10], p3[10];

int read_poly(struct poly[])
{
    int n1;
    printf("Enter no. of terms in p1: ");
    scanf("%d", &n1);

    printf("Enter coef of each term: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &p1[i].coef);
    }

    printf("Enter expo of each term: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &p1[i].expo);
    }
}

int add_poly(struct poly[], struct poly[], int, int, struct poly[]);

void display(struct poly*, int n1)
{
    printf("p1: ");
    for (int i = 0; i < n1 - 1; i++)
    {
        printf("%dx^%d + ", p1[i].coef, p1[i].expo);
    }
    printf("%dx^%d \n", p1[n1 - 1].coef, p1[n1 - 1].expo);

    printf("------------------------------\n");
}

int main()
{

    int t1, t2, t3;
    int n1, n2;

    read_poly(p1);
    display(p1, n1);

    printf("Enter no. of terms in p2: ");
    scanf("%d", &n2);

    printf("Enter coef of each term: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &p2[i].coef);
    }

    printf("Enter expo of each term: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &p2[i].expo);
    }

    printf("p2: ");
    for (int i = 0; i < n2 - 1; i++)
    {
        printf("%dx^%d + ", p2[i].coef, p2[i].expo);
    }
    printf("%dx^%d \n", p2[n2 - 1].coef, p2[n2 - 1].expo);

    // add

    printf("------------------------------\n");
    printf("ADD\n");
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (p1[i].expo == p2[i].expo)
        {
            p3[k].coef = p1[i].coef + p2[i].coef;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        }

        else if (p1[i].expo > p2[i].expo)
        {
            p3[k].coef = p1[i].coef;
            p3[k].expo = p1[i].expo;
            i++, k++;
        }

        else
        {
            p3[k].coef = p2[i].coef;
            p3[k].expo = p2[i].expo;
            j++, k++;
        }
    }

    while (i < n1)
    {
        p3[k].coef = p1[i].coef;
        p3[k].expo = p1[i].expo;
        i++, k++;
    }

    while (j < n2)
    {
        p3[k].coef = p2[i].coef;
        p3[k].expo = p2[i].expo;
        j++, k++;
    }

    printf("p3: ");
    for (int i = 0; i < n1 - 1; i++)
    {
        printf("%dx^%d + ", p3[i].coef, p3[i].expo);
    }
    printf("%dx^%d \n", p3[n1 - 1].coef, p3[n1 - 1].expo);

    return 0;
}




