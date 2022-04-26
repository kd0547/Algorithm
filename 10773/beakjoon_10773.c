/*
 ����
 ���ڴ� ���� ����̴� ���Ƹ� ȸ���� �غ��ϱ� ���ؼ� ��θ� �����ϴ� ���̴�.
 �����̴� ����̸� ���ͼ� ���� �����ϴ� ���ε�, �ּ��ϰԵ� �׻� ���ž��� �����̴� ���� �Ǽ��� �߸� �θ��� ��� ġ�� �Ͼ�����.
 �����̴� �߸��� ���� �θ� ������ 0�� ���ļ�, ���� �ֱٿ� ����̰� �� ���� ����� ��Ų��.
 ����̴� �̷��� ��� ���� �޾� ���� �� �� ���� ���� �˰� �;� �Ѵ�. ����̸� ��������!

 �Է�
 ù ��° �ٿ� ���� K�� �־�����. (1 �� K �� 100,000)
 ���� K���� �ٿ� ������ 1���� �־�����. ������ 0���� 1,000,000 ������ ���� ������, ������ "0" �� ��쿡�� ���� �ֱٿ� �� ���� �����, �ƴ� ��� �ش� ���� ����.
 ������ "0"�� ��쿡 ���� �� �ִ� ���� ������ ������ �� �ִ�.

 ���
 ����̰� ���������� ���� �� ���� ���� ����Ѵ�. ���������� ��� ���� ���� 2^31-1���� �۰ų� ���� �����̴�.

 ���� �Է�				���� ���
 4					0
 3
 0
 4
 0

 ���� �Է�				���� ���
 10					7
1
 3
 5
 4
 0
 0
 7
 0
 0
 6


*/


#include<stdio.h>

#define MAX 100000
int stack[MAX];
int top = 0;

void pop()
{
	stack[top] = 0;
}
void push(int data)
{
	stack[top] = data;
}


int main()
{

	int input;
	int k; //k - ����� �Է�
	int sum = 0;

	scanf("%d", &k);


	for (int i = 0; i < k; i++)
	{
		scanf("%d", &input);
		if (input == 0)
		{
			top--;
			pop();
		}
		else
		{
			push(input);
			top++;
		}
	}
	for (int i = 0; i < k; i++)
	{
		sum += stack[i];
	}
	printf("%d", sum);

	return 0;
}
--------------------------------------------------------------------------------------------------------------------------------------------
/*
  ���� ������ ����
  ������ ���� ������ ������
  ������ �ƴ�
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node* NEXTNODE;
	int data;
}NODE;

typedef struct list
{
	NODE* List;
	NODE* Top;
}List;
void create_List(List** Stack)
{
	(*Stack) = (List*)malloc(sizeof(List));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}
NODE* create_Node(int Data)
{
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->data = Data;
	node->NEXTNODE = NULL;

	return node;
}


void push(List* Stack, NODE* newnode)
{
	if (Stack->List == NULL)
	{
		Stack->List = newnode;
	}
	else
	{
		NODE* top = Stack->List;
		while (top->NEXTNODE != NULL)
		{
			top = top->NEXTNODE;
		}
		top->NEXTNODE = newnode;
	}

	Stack->Top = newnode;
}
NODE* pop(List* List)
{
	NODE* TopNode = List->Top;
	if (List->List == List->Top)
	{
		List->List = NULL;
		List->Top = NULL;
	}
	else
	{
		NODE* SearchTop = List->List;
		while (SearchTop->NEXTNODE != TopNode)
		{
			SearchTop = SearchTop->NEXTNODE;
		}
		List->Top = SearchTop;
		SearchTop->NEXTNODE = NULL;
	}
	return TopNode;
}
int addstack(List* stack)
{
	int sum = 0;
	NODE* node = stack->List;
	while (node->NEXTNODE != NULL)
	{
		sum += node->data;
		node = node->NEXTNODE;
	}
	sum += node->data;
	return sum;
}

void main() {
	int k;
	int input;
	List* stack;
	List* popData;
	NODE* node;
	create_List(&stack);

	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		scanf("%d", &input);

		if (input == 0)
		{
			popData = pop(stack);
		}
		else
		{
			node = create_Node(input);
			push(stack, node);
		}


	}

	printf("%d\n", addstack(stack));
}





