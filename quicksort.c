#include <stdio.h>
#include <stdlib.h>

void quicksort(int *a, int left, int right);
void swap(int *a, int *b);

int main(void)
{
    int maxSize = 10;
    int *a = malloc(maxSize * sizeof(int));
    if (a == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int i = 0;
    char next = 'y';

    printf("Enter up to %d numbers. Enter a non-integer to stop.\n", maxSize);

    while (i < maxSize)
    {
        printf("Enter a number (or a non-integer to stop): ");
        if (scanf("%d", &a[i]) != 1)
        {
            break;
        }

        i++;
    }

    printf("\nOriginal array: ");
    for (int j = 0; j < i; j++)
        printf("%d ", a[j]);
    printf("\n");

    quicksort(a, 0, i - 1);

    printf("Sorted array: ");
    for (int j = 0; j < i; j++)
        printf("%d ", a[j]);
    printf("\n");

    free(a);
    return 0;
}

void quicksort(int *a, int left, int right)
{
    int i, j, pivot;

    if (left >= right)
        return;

    pivot = a[left];
    i = left + 1;
    j = right;

    printf("Pass: ");
    for (int k = left; k <= right; k++)
        printf("%d ", a[k]);
    printf("\n");

    while (1)
    {
        while (i <= right)
        {
            if (a[i] > pivot)
                break;
            i++;
        }
        while (j > left)
        {
            if (a[j] < pivot)
                break;
            j--;
        }
        if (i > j)
            break;
        swap(&a[i], &a[j]);

        printf("Swap: ");
        for (int k = left; k <= right; k++)
            printf("%d ", a[k]);
        printf("\n");
    }
    swap(&a[left], &a[j]);

    printf("Pivot: %d\n", pivot);
    printf("Result: ");
    for (int k = left; k <= right; k++)
        printf("%d ", a[k]);
    printf("\n\n");

    quicksort(a, left, j - 1);
    quicksort(a, j + 1, right);
}

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
