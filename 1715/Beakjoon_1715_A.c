#include<stdio.h>
#include<stdlib.h>



typedef struct tagQueue
{
	
	int tree[100000];
	int UsedSize;
}Queue;

void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int parent(int index);
int leftChild(int index);
int rightChild(int index);
void swap(Queue* queue, int child, int parent);

struct tagQueue queue;
const int size = 100000;

int main()
{


	int N = 1, temp = 0;
	long long total = 0;

	scanf_s("%d", &N);
	
	queue.UsedSize = 0;

	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &temp);
		enqueue(&queue, temp);
	}

	/*if (queue.UsedSize == 1)
	{
		
	}*/

	while (queue.UsedSize > 1)
	{
		int a = dequeue(&queue);
		int b = dequeue(&queue);

		long long sum = (long long)(a + b);
		total += sum;

		enqueue(&queue, sum);

		
	}

	printf("%lld", total);
	


	return 0;
}
void enqueue(Queue* queue, int data)
{
	int CurrentPosition = queue->UsedSize;
	int parentPosition = parent(CurrentPosition);

	if (CurrentPosition == size)
	{
		return;
	}

	queue->tree[CurrentPosition] = data;


	while (CurrentPosition > 0 && queue->tree[CurrentPosition] < queue->tree[parentPosition])
	{
		swap(queue, CurrentPosition, parentPosition);

		CurrentPosition = parentPosition;
		parentPosition = parent(CurrentPosition);

	}
	queue->UsedSize++;
}

int dequeue(Queue* queue)
{

	int ParentPosition = 0;
	int leftPosition = 0;
	int rightPosition = 0;

	int remove = queue->tree[0];

	//노드 삭제
	queue->tree[0] = 0;
	// 마지막 노드와 스왑 마지막 노드와 바꾸면 가장 루트는 트리에서 가장 큰 값이 된다. 
	queue->UsedSize--;
	swap(queue, queue->UsedSize, 0);

	leftPosition = leftChild(0);
	rightPosition = leftPosition + 1;


	while (1)
	{
		//첫번째 회전은 root
		int SelectedChild = 0;

		if (leftPosition >= queue->UsedSize)
			break;

		if (rightPosition >= queue->UsedSize)
		{
			SelectedChild = leftPosition;
		}
		else
		{
			if (queue->tree[leftPosition] < queue->tree[rightPosition])
				SelectedChild = leftPosition;
			else
				SelectedChild = rightPosition;
		}


		if (queue->tree[ParentPosition] > queue->tree[SelectedChild])
		{
			swap(queue, SelectedChild, ParentPosition);
			ParentPosition = SelectedChild;
		}
		else
			break;

		leftPosition = leftChild(ParentPosition);
		rightPosition = leftPosition + 1;
	}


	return remove;
}

int parent(int index)
{
	return (int)((index - 1) / 2);
}
int leftChild(int index)
{
	return index * 2 + 1;
}
int rightChild(int index)
{
	return index * 2;
}
void swap(Queue* queue, int child, int parent)
{
	int temp = queue->tree[child];

	queue->tree[child] = queue->tree[parent];
	queue->tree[parent] = temp;
}