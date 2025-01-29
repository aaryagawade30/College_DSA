#include <stdio.h>
#include <stdlib.h>

int main()
{

	int n, key, temp, ch, flag = 0, found = 0;
	int mid;
	int first = 0;
	int last = n - 1;
	printf("Enter size of array: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter elements of array: \n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Unsorted array: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");

	// bubble sort
	for (int i = 1; i < n; i++)
	{
		// comp += 1;
		for (int j = 0; j < n - i; j++)
		{
			// swap += 1;
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	printf("Sorted array: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");

	printf("Enter key which you want to search for: ");
	scanf("%d", &key);

	do
	{
		printf("Menu:\n");
		printf("1. Linear Search\n");
		printf("2. Binary Search\n");
		printf("3. Exit\n");
		printf("Enter corresponding number for searching type or exit: ");
		scanf("%d", &ch);

		switch (ch)
		{

		case 1:

			// Linear search

			for (int i = 0; i < n; i++)
			{
				if (a[i] == key)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				printf("%d is found in given array.\n", key);
			}
			else
			{
				printf("%d is not found,\n", key);
			}
			break;

		case 2:
			// Binary search

			while (first < last)
			{
				mid = (first + last) / 2;
				if (key > a[mid])
				{
					first = mid + 1;
				}
				else if (key < a[mid])
				{
					last = mid - 1;
				}
				else
				{
					found = 1;
					printf("%d is present at %d \n", key, first);
					break;
				}
			}
			if (last < first)
			{
				printf("%d is not found.\n", key);
			}

			break;

		case 3:
			exit(0);

		default:
			printf("Invalid choice.");
		}
		break;
		break;
	} while (ch < 4);

	return 0;
}