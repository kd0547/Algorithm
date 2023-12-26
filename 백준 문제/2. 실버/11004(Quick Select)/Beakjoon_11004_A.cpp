#include<iostream>
#include<vector>

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

	QuickSelect(array1, 0,n-1);

	cout << array1[k-1] << endl;


}

int partition(int source[], int left, int right)
{
	int pivot;
	int low, high;

	low = left;
	high = right;
	pivot = left;

	while (low < high)
	{
		while (low <= right && source[low] < source[pivot])
			low++;

		while (high >= left && source[high] > source[pivot])
			high--;

		if (left < right)
			swap(source[low], source[high]);
	}
	
	swap(source[left], source[high]);


	return high;
}

void QuickSelect(int source[], int left, int right)
{
	if (left < right)
	{
		int pivot = partition(source, left, right);

		QuickSelect(source, left, pivot - 1);
		QuickSelect(source, pivot + 1, right);
	}
}