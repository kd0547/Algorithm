#include <stdio.h>

#define MAX 100001

int rope[MAX];

void QuickSelect(int *Array, int start, int end);
void swap(int *a, int *b);
int max(int max, int src);
int main()
{
	int N;
	int max_weight = 0;
	int share_weight = 0;
	int w = 0, k = 1;

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &rope[i]);
	}

	QuickSelect(rope, 0, N - 1);

	while (k <= N)
	{
		w = rope[k - 1];

		share_weight = k * w;

		if (1 == max(max_weight, share_weight))
		{
			max_weight = share_weight;
		}

		k++;
	}
	printf_s("%d", max_weight);

	// w/k
}
int max(int max, int src)
{
	if (max < src)
		return 1;
	else
		return 0;
}

void QuickSelect(int *array, int left, int right)
{

	if (left >= right)
		return;

	int pivot = left;
	int start = left + 1;
	int end = right;

	while (start <= end)
	{
		while (array[pivot] <= array[start] && start <= right)
			start++;
		while (array[pivot] >= array[end] && end > left)
			end--;

		if (start > end)
		{
			swap(&array[pivot], &array[end]);
		}
		else
		{
			swap(&array[start], &array[end]);
		}
	}
	QuickSelect(array, left, end - 1);
	QuickSelect(array, end + 1, right);
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}