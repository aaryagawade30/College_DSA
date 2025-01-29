#include <stdio.h>

struct poly
{
    int coeff;
    int expo;
};

struct poly p1[10], p2[10], p3[10];

int read_poly(struct poly[]);
int add_poly(struct poly[], struct poly[], int, int, struct poly[]);
void display(struct poly[], int terms);

int main()
{
    int t1, t2, t3;

    t1 = read_poly(p1);
    printf("first polynomial\n");
    display(p1, t1);

    t2 = read_poly(p2);
    printf("second polynomial\n");
    display(p2, t2);

    t3 = add_poly(p1, p2, t1, t2, p3);

    printf("resultant polynomial after addition\n");

    display(p3, t3);

    return 0;
}

int read_poly(struct poly p[10])
{
    int t1, i;
    printf("Enter no. of terms\n");
    scanf("%d", &t1);

    printf("Enter coefficient and exponent in descending order\n");

    for (i = 0; i < t1; i++)
    {
        printf("Enter the coefficient %d\n", i + 1);
        scanf("%d", &p[i].coeff);

        printf("Enter the exponent %d\n", i + 1);
        scanf("%d", &p[i].expo);
    }

    return t1;
}

void display(struct poly p[10], int terms)
{
    int k;
    for (k = 0; k < terms - 1; k++)
    {
        printf("%dX^%d +", p[k].coeff, p[k].expo);
    }
    printf("%dx^%d + ", p[terms - 1].coeff, p[terms - 1].expo);
}

int add_poly(struct poly p1[10], struct poly p2[10], int t1, int t2, struct poly p3[10])
{
    int i = 0, j = 0, k = 0;
    while (i < t1 && j < t2)
    {
        if (p1[i].expo == p2[i].expo)
        {
            p3[k].coeff = p1[i].coeff + p2[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        }
        else if (p1[i].expo > p2[i].expo)
        {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;

            i++;
            k++;
        }
        else
        {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;

            j++;
            k++;
        }
    }

    while (i < t1)
    {
        p3[k].coeff = p2[i].coeff;
        p3[k].expo = p2[i].expo;
        i++;
        k++;
    }
    while (j < t2)
    {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }
    return (k);
}