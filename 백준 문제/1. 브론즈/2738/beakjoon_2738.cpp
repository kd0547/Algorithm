#include<iostream>

using namespace std;

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;

	int** array1 = new int* [n];
	int** array2 = new int* [n];
	int** result = new int* [n];

	for (int i = 0; i < n; i++)
	{
		array1[i] = new int[m];
		array2[i] = new int[m];
		result[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> array1[i][j];
		}
		
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> array2[i][j];
		}
		
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result[i][j] = array1[i][j] + array2[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf_s("%d ", result[i][j]);
		}
		printf_s("\n");
	}

	return 0;
}
