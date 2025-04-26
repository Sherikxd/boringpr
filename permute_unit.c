#include "permute_unit.h"
#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *a, int l, int r)
{
    int i;
    if (l == r)
    {
        for (i = 0; i <= r; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + i)); // backtrack
        }
    }
}
void permute_unit()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Permutations:\n");
    permute(a, 0, n - 1);
}