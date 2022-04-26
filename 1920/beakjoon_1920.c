/*
  문제
  N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

  입력
  첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다.
  다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

  출력
  M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.

  예제 입력         예제 출력
  5                 1
  4 1 5 2 3         1
  5                 0
  1 3 7 9 5         0
                    1




  ************************************************************************************************
  이 문제는 퀵 정렬 -> 이진탐색으로 푸는 문제였다.

  값 자체는 나오는데 백준에서는 통과하지 못했음 내 코드 아래에 정답 코드도 같이 올릴건데
  이건 나중에 천천히 비교해봐야겠다.


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


   정답 코드


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












