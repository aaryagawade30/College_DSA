#include <stdio.h>
#include <string.h>


struct student
{
    int roll_no, DS, DE, SS, total;
    char name[50];
    float avg;
};
struct student s[5], temp;

void display(int n)
{

    int i;

    printf("The Student database is as follows.\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("|\tRoll no\t|\tName\t|\tDS\t|\tDE\t|\tSS\t|\tTotal\t|\tAvg\t\t|\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("|\t%d\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%f\t|\n", s[i].roll_no, s[i].name, s[i].DS, s[i].DE, s[i].SS, s[i].total, s[i].avg);
        printf("_--------------------------------------------------------------------------------------------------------------------\n");
    }
}


int main()
{
    int i, n;

    printf("Enter the number of the students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("--------------------------------------------------------------------------------\n");
        printf("Enter the information of the student %d.\n", i + 1);
        printf("Enter the Roll no: ");
        scanf("%d", &s[i].roll_no);
        printf("Enter the name: ");
        scanf("%s", s[i].name);
        printf("Enter the marks of DS, DE, SS: ");
        scanf("%d%d%d", &s[i].DS, &s[i].DE, &s[i].SS);

        s[i].total = (s[i].DS + s[i].DE + s[i].SS);
        s[i].avg = s[i].total / 3;
    }
    display(n);

    while (1)
    {
        int ch, a, pos, n1, m, p, roll, new;
        char search[30];
        printf("\nMenu\n1.Search\n2.Append\n3.Sorting\n4.Modify\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            printf("Enter name: ");
            scanf("%s", search);

            for (i = 0; i < n; i++)
            {
                a = strcmp(search, s[i].name);

                if (a == 0)
                {
                    pos = i;
                    break;
                }
            }

            if (a == 0)
            {
                printf("|\tRoll no\t|\tName\t|\tDS\t|\tDE\t|\tSS\t|\tTotal\t|\tAvg\t\t|\n");
                printf("--------------------------------------------------------------------------------------------------------------\n");
                printf("\n|\t%d\t|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%f\t|\n", s[pos].roll_no, s[pos].name, s[pos].DS, s[pos].DE, s[pos].SS, s[pos].total, s[i].avg);
            }
            else
                printf("Name not found.\n");

            break;
        case 2:
            printf("Enter the entries to be add: ");
            scanf("%d", &n1);

            m = n + n1;

            for (i = n; i < m; i++)
            {

                printf("Enter the information of the student %d.\n", i + 1);
                printf("Enter the Roll no: ");
                scanf("%d", &s[i].roll_no);
                printf("Enter the name: ");
                scanf("%s", s[i].name);
                printf("Enter the marks of DS, DE, SS: ");
                scanf("%d%d%d", &s[i].DS, &s[i].DE, &s[i].SS);
                s[i].total = (s[i].DS + s[i].DE + s[i].SS);
                s[i].avg = s[i].total / 3;
            }
            n = m;

            printf("The updated database is as follows\n");
            display(n);

            break;

        case 3:
            for (p = 1; p < n; p++)
            {
                for (int c = 0; c < n - p; c++)
                {
                    if (s[c].roll_no > s[c + 1].roll_no)
                    {
                        temp = s[c];
                        s[c] = s[c + 1];
                        s[c + 1] = temp;
                    }
                }
            }
            display(n);

            break;

        case 4:

            printf("\nEnter the roll no that you want to modify: ");
            scanf("%d", &roll);
            printf("Enter the new roll no: ");
            scanf("%d", &new);

            for (i = 0; i < n; i++)
            {
                if (s[i].roll_no == roll)
                {
                    s[i].roll_no = new;
                }
            }

            printf("The updated database is as follows\n");
            display(n);

            break;
        }
        break;
    }

    return 0;
}
