#include<iostream>

using namespace std;

#define MAX 1001

int main()
{

	int* array1 = new int[MAX] {0, };
	int n = 0, k = 0;
	
	cin >> n >> k;

	
	int* narray = new int[n] {0, };
	int whileCount = 0;
	int i = 0;
	int count = 0;

	int a = n;
	while (a != 0)
	{
		for (int j = 1; j <= n; j++)
		{
			if (count != k && array1[j] == 0)
			{
				count++;
			}

			if (count == k && array1[j] != 1)
			{
				array1[j] = 1;
				count = 0;

				narray[whileCount] = j;
				whileCount++;

				a--;
			}
		}
	}

	printf_s("<");
	for (int i = 0; i < n; i++)
	{
		printf_s("%d", narray[i]);

		if (i != n - 1)
		{
			printf_s(", ");
		}

		

	}
	printf_s(">");


	



	return 0;
}