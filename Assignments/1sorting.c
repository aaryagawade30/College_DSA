#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, j, swap, comp, temp, index, small, ch;
	printf("Enter size of array: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter elements of array: \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Unsorted array: \n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");

	
	do
	{
		printf("Menu:\n");
		printf("1. Bubble sort\n");
		printf("2. Insertion sort\n");
		printf("3. Selection sort\n");
		printf("4. Exit\n");
		printf("Enter corresponding number for sorting type or exit: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			// bubble sort
			for (i = 1; i < n; i++)
			{
				comp += 1;
				for (j = 0; j < n - i; j++)
				{
					swap += 1;
					if (a[j] > a[j + 1])
					{
						temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
				}
			}

			printf("Sorted array: \n");
			for (i = 0; i < n; i++)
			{
				printf("%d\t", a[i]);
			}
			printf("\n");
			break;

		case 2:
			// insertion sort
			for (i = 1; i < n; i++)
			{
				index = a[i];
				for (j = i - 1; j >= 0; j--)
				{
					if (a[j] > index)
					{
						a[j + 1] = a[j];
					}
					else
						break;
				}
				a[j + 1] = index;
			}

			printf("Sorted array: \n");
			for (i = 0; i < n; i++)
			{
				printf("%d\t", a[i]);
			}
			printf("\n");
			break;

		case 3:
			// selection sort
			for (i = 1; i < n; i++)
			{
				small = i - 1;
				for (j = i; j < n; j++)
				{
					if (a[j] < a[small])
					{
						small = j;
					}

					if (small != i - 1)
					{
						temp = a[small];
						a[small] = a[i - 1];
						a[i - 1] = temp;
					}
				}
			}

			printf("Sorted array: \n");
			for (i = 0; i < n; i++)
			{
				printf("%d\t", a[i]);
			}
			printf("\n");
			break;
		case 4:
			exit(0);

		default:
			printf("Invalid choice.");
			break;
		}
		break;
	}

	while (ch < 4);

	return 0;
}
