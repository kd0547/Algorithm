#include<stdio.h>
#include<stdlib.h>
#include<memory.h>


typedef struct j
{
	int mass;
	int val; 
}Info;

#define padding 5;

int parent(int currentPosition);
void push(Info* arr, Info info,int* usedSize);
Info pop(Info* arr, int* usedSize);
int leftChild(int parentPosition);
void Swap(Info* arr,int index1, int index2);
void Delete(Info* arr, int* usedSize);
int usedSize_jw = 0;
int usedSize_bag = 0;
//Info* jw = NULL;
//Info* bag = NULL;
//Info * jw_backup = NULL;


Info jw[300001];
Info bag[300001] ;
Info jw_backup[300001];
Info clear = { -1L,-1L };

//https://www.acmicpc.net/problem/1202
int main()
{
	long long sum = 0;
	int N, K;

	scanf_s("%d %d", &N, &K);

	int N_size = N + padding;
	int K_size = K + padding;

	/*jw = (Info*)malloc(sizeof(Info) * N_size);
	jw_backup = (Info*)malloc(sizeof(Info) * N_size);
	bag = (Info*)malloc(sizeof(Info) * K_size);
	*/
	for (int i = 0; i < N; i++)
	{
		int M, V;
		scanf_s("%ld %ld", &M, &V);
		Info newInfo = {M, V};
		push(&jw,newInfo, &usedSize_jw);
	}

	for (int i = 0; i < K; i++)
	{
		int g = 0;
		scanf_s("%ld", &g);
		Info newInfo = { 0,g };

		push(&bag,newInfo, &usedSize_bag);
	}

	while (usedSize_bag != 0)
	{
		Info bag_a = pop(&bag, &usedSize_bag);
		
		int j = 0;
		while (j < N)
		{
			Info jw_a = pop(&jw, &usedSize_jw);
			if (jw_a.val == -1)
			{
				break;
			}

			if (jw_a.mass == 0)
			{
				Delete(&bag, &usedSize_bag);
				push(&bag, bag_a, &usedSize_bag);

				sum = sum + (long long)jw_a.val;
				break;
			}


			if (jw_a.mass <= bag_a.val)
			{
				sum = sum + (long long) jw_a.val;
				break;
			}
			
		}
		
		

	}

	
	
	


	printf_s("%lld\n",sum);


	return 0;
}

void Delete(Info* arr, int* usedSize)
{
	if (*usedSize > 0)
	{
		*usedSize = *usedSize - 1;

		int size = *usedSize;

		arr[size] = clear;
	}
}

void push(Info* arr,Info info, int* usedSize)
{
	
	if (*usedSize == -1)
	{
		*usedSize = 0;
	}
	int size = *usedSize;

	int currentPosition = *usedSize;
	int parentPosition = parent(currentPosition);

	arr[currentPosition] = info;
	
	while (currentPosition > 0 && arr[currentPosition].val > arr[parentPosition].val)
	{
		Swap(arr,currentPosition, parentPosition);
		currentPosition = parentPosition;
		parentPosition = parent(currentPosition);
	}
	*usedSize = size + 1;
}

Info pop(Info* arr, int* usedSize)
{
	


	Info remove = { -1L,-1L };
	int parentPosition = 0;
	int leftPosition = 0;
	int rightPosition = 0;

	remove = arr[parentPosition];
	memset(&arr[parentPosition], -1, sizeof(Info));
	//arr[parentPosition] = clear;

	*usedSize = *usedSize - 1;
	if (*usedSize == -1)
	{
		*usedSize = 0;
	}

	Swap(arr, parentPosition, *usedSize);


	leftPosition = leftChild(parentPosition);
	rightPosition = leftPosition + 1;

	while (1)
	{
		int select = 0;

		if (leftPosition >= *usedSize)
			break;

		if (rightPosition >= *usedSize)
		{
			select = leftPosition;
		}
		else
		{
			if (arr[rightPosition].val > arr[leftPosition].val)
			{
				select = rightPosition;
			}
			else
			{
				select = leftPosition;
			}
		}

		if (arr[select].val > arr[parentPosition].val)
		{
			Swap(arr,parentPosition, select);
			parentPosition = select;
		}
		else
		{
			break;
		}

		leftPosition = leftChild(parentPosition);
		rightPosition = leftPosition + 1;
	}


	return remove;
}


int parent(int currentPosition)
{
	return (int)((currentPosition - 1 )/ 2);
}

int leftChild(int parentPosition)
{
	return (parentPosition * 2) + 1;
}



void Swap(Info* arr,int index1, int index2)
{
	Info temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}