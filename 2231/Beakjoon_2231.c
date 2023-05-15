#include<stdio.h>
#include<stdlib.h>

int min(int src, int max);
int max = 1000001;

int main()
{
	int n, i = 0;
	int sum = 0;
	scanf_s("%d", &n);

	for (i = 1; i < n; i++)
	{
		sum = i;
		int j = i;
		while (j != 0)
		{
			sum = sum + (j % 10);
			j = j / 10;
		}
		if (sum == n)
			max = min(i, max);
	}

	if (max != 1000001)
		printf_s("%d\n", max);
	else 
		printf_s("%d\n", 0);
	return 0;
}

int min(int src, int max1)
{
	return src < max1 ?  src : max1;
}