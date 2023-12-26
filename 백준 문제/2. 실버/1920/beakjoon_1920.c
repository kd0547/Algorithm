#include <stdio.h>
#include <stdlib.h>

int n[100000];
int m[100000];

void swap(int *a, int *b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

int partition(int *arry, int left, int right)
{

    int mid = (left + right) / 2;
    int pivot = arry[mid];

    while (left <= right)
    {
        while (arry[left] <= pivot && left <= right)
            ++left;
        while (arry[right] > pivot && left <= right)
            --right;
        if (left <= right)
        {
            swap(&arry[left], &arry[right]);
        }
        else
            break;
    }
    if (pivot > arry[right])
    {
        swap(&arry[mid], &arry[right]);
    }
    return right;
};
void quick_sort(int *arry, int left, int right)
{

    if (left < right)
    {
        int p = partition(arry, left, right);

        quick_sort(arry, left, p - 1);
        quick_sort(arry, p + 1, right);
    }
};

int binary_search(int *arry, int target, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arry[mid] == target)
            return 1;
        else if (arry[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{

    int n_Len, m_Len;

    scanf_s("%d", &n_Len);
    for (int i = 0; i < n_Len; i++)
    {
        scanf_s("%d", &n[i]);
    }
    quick_sort(n, 0, n_Len - 1);

    scanf_s("%d", &m_Len);
    for (int i = 0; i < m_Len; i++)
    {
        scanf_s("%d", &m[i]);
    }

    for (int i = 0; i < n_Len; i++)
    {
        if (binary_search(n, m[i], 0, n_Len - 1) != -1)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}
