#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct stack
{
    int stk[MAX];
    int top;
} st;

int main()
{
    int num, x, i, ch;
    int top = -1;
    do
    {

        printf("Enter choice: 1. Push, 2. Pop, 3. Display, 4. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: // push
            if (st.top == MAX - 1)
                printf("Full Stack");
            else
            {
                printf("Data to be pushed: \n");
                scanf("%d", &num);
                st.top++;
                st.stk[st.top] = num;
            }
            break;

        case 2: // pop

            if (st.top == -1)
                printf("Empty Stack");
            else
            {
                x = st.stk[st.top];
                st.top--;
                printf("Popped element: %d\n", x);
            }
            break;

        case 3: // display

            if (st.top == -1)
                printf("Empty Stack");
            else
            {
                for (i = st.top; i > 0; i--)
                {
                    printf("%d", st.stk[i]);
                }
                printf("\n");
            }
            break;

        default:
            exit(0);
        }

    } while (ch != 4);

    return 0;
}