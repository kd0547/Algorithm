#include <iostream>
#include <vector>

using namespace std;

void QuickSelect(int source[], int left, int right);
int partition(int source[], int left, int right);
int array1[5000001];

int n = 0;
int k = 0;

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> array1[i];
	}

	QuickSelect(array1, 0, n - 1);

	cout << array1[k - 1] << endl;
}

int partition(int source[], int left, int right)
{
	int pivot = source[left];
	int low = left + 1, high = right;
	while (low <= right)
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
	if (select > 0 && select >= right - left + 1)
	{
		int pivot_index = partition(source, left, right);

		if(pivot_index - left == select -1)
		{
			return source[pivot_index];
		}
		else if(pivot_index - left > select - 1)
		{
			return QuickSelect(source,left,pivot_index-1,select);
		}
		else
		{
			return QuickSelect(source,pivot_index+1,right,select);
		}

	}
}