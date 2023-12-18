#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b);
void push(int data);
int pop();
int parent(int child);
int leftChild(int parent);
int rightChild(int parent);

int UsedSize = 0;
int capacity = 0;
int* arr;

int main()
{
	int N = 0;
	scanf_s("%d", &N);

	capacity = N;

	arr = (int*)malloc(sizeof(int) * capacity);


	for (int i = 0; i < N; i++)
	{
		int S;
		scanf_s("%d", &S);
		push(S);
	}


	for (int i = 0; i < N; i++)
	{
		printf_s("%d \n", pop());
	}



	return 0;
}

void push(int data)
{
	int currentPosition = UsedSize;
	int parentPosition = parent(currentPosition);


	if (UsedSize >= capacity)
	{
		if (capacity == 0)
			capacity = 1;

		capacity *= 2;
		arr = (int*)realloc(arr, (int)capacity);
	}

	arr[currentPosition] = data;

	while (currentPosition > 0 && arr[currentPosition] < arr[parentPosition])
	{
		swap(&arr[currentPosition], &arr[parentPosition]);

		currentPosition = parentPosition;

		parentPosition = parent(currentPosition);
	}
	UsedSize++;
}

int pop()
{
	int parentPosition = 0;
	int leftPosition = 0;
	int rightPosition = 0;

	int pop = arr[parentPosition];
	arr[parentPosition] = -1;

	UsedSize--;
	swap(&arr[parentPosition], &arr[UsedSize]);

	leftPosition = leftChild(parentPosition);
	rightPosition = rightChild(parentPosition);

	while (1)
	{
		int selectPosition = 0;

		if (leftPosition >= UsedSize)
			break;

		if (rightPosition >= UsedSize)
		{
			selectPosition = leftPosition;
		}
		else
		{
			if (arr[leftPosition] < arr[rightPosition])
			{
				selectPosition = leftPosition;
			} 
			else
			{
				selectPosition = rightPosition;
			}
		}

		if (arr[parentPosition] > arr[selectPosition])
		{
			swap(&arr[parentPosition], &arr[selectPosition]);
			parentPosition = selectPosition;
		}
		else
			break;
		

		leftPosition = leftChild(parentPosition);
		rightPosition = rightChild(parentPosition);

		if (UsedSize < (capacity /2))
		{
			capacity /= 2;
			arr = (int*)realloc(arr, sizeof(int) * capacity);
		}
	}



	return pop;
}
int parent(int child)
{
	return (int)(child / 2);
}
int leftChild(int parent)
{
	return parent * 2;
}
int rightChild(int parent)
{
	return (parent * 2) + 1;
}


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}