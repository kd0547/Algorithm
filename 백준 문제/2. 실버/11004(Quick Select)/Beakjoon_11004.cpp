#include <iostream>
#include <vector>

using namespace std;

int QuickSelect(int source[], int left, int right, int select);
int partition(int source[], int left, int right);
int array1[5000001];

int n = 0;
int k = 0;

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> array1[i];
	}

	int result = QuickSelect(array1, 1, n, k);

	cout << result << endl;
}

int partition(int source[], int left, int right)
{
	int pivot = source[left];
	int low = left + 1, high = right;
	while (low <= high)
	{
		while (low <= right && source[low] <= pivot)
			low++;
		while (high > (left + 1) && source[high] >= pivot)
			high--;

		if (low <= high)
			swap(source[low], source[high]);
	}
	swap(source[left], source[high]);

	return high;
}

int QuickSelect(int source[], int left, int right, int select)
{
	int pivot_index = partition(source, left, right);

	if (pivot_index - left == select - 1)
	{
		return source[pivot_index];
	}
	else if (pivot_index - left > select - 1)
	{
		return QuickSelect(source, left, pivot_index - 1, select);
	}
	else
	{
		return QuickSelect(source, pivot_index + 1, right, select);
	}
}