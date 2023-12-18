/*
  ����
  N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

  �Է�
  ù° �ٿ� �ڿ��� N(1 �� N �� 100,000)�� �־�����. ���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����. ���� �ٿ��� M(1 �� M �� 100,000)�� �־�����.
  ���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�. ��� ������ ������ -231 ���� ũ�ų� ���� 231���� �۴�.

  ���
  M���� �ٿ� ���� ����Ѵ�. �����ϸ� 1��, �������� ������ 0�� ����Ѵ�.

  ���� �Է�         ���� ���
  5                 1
  4 1 5 2 3         1
  5                 0
  1 3 7 9 5         0
                    1




  ************************************************************************************************
  �� ������ �� ���� -> ����Ž������ Ǫ�� ��������.

  �� ��ü�� �����µ� ���ؿ����� ������� ������ �� �ڵ� �Ʒ��� ���� �ڵ嵵 ���� �ø��ǵ�
  �̰� ���߿� õõ�� ���غ��߰ڴ�.


*/









#include<stdio.h>
#include<stdlib.h>

int n[100000];
int m[100000];

void swap(int* a, int* b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

int partition(int* arry, int left, int right)
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
void quick_sort(int* arry, int left, int right)
{


    if (left < right)
    {
        int p = partition(arry, left, right);

        quick_sort(arry, left, p - 1);
        quick_sort(arry, p + 1, right);
    }
};

int binary_search(int* arry, int target, int low, int high)
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








/*


   ���� �ڵ�


*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int binary_search(int arr[], int num, int size)
{
    int front, rear, pivot;
    front = 0;
    rear = size - 1;
    while (1) {
        pivot = (front + rear) / 2;
        if (arr[pivot] == num) return 1;
        if (arr[front] == num) return 1;
        if (arr[rear] == num) return 1;

        if (arr[pivot] < num)
            front = pivot + 1;
        else
            rear = pivot - 1;
        if (front >= rear)
            return 0;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int m;
    scanf("%d", &m);
    int* arr2 = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    for (int j = 0; j < m; j++) {
        printf("%d\n", binary_search(arr, arr2[j], n));
    }
    return 0;
}












