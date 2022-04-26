/*
 문제
 나코더 기장 재민이는 동아리 회식을 준비하기 위해서 장부를 관리하는 중이다.
 재현이는 재민이를 도와서 돈을 관리하는 중인데, 애석하게도 항상 정신없는 재현이는 돈을 실수로 잘못 부르는 사고를 치기 일쑤였다.
 재현이는 잘못된 수를 부를 때마다 0을 외쳐서, 가장 최근에 재민이가 쓴 수를 지우게 시킨다.
 재민이는 이렇게 모든 수를 받아 적은 후 그 수의 합을 알고 싶어 한다. 재민이를 도와주자!

 입력
 첫 번째 줄에 정수 K가 주어진다. (1 ≤ K ≤ 100,000)
 이후 K개의 줄에 정수가 1개씩 주어진다. 정수는 0에서 1,000,000 사이의 값을 가지며, 정수가 "0" 일 경우에는 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.
 정수가 "0"일 경우에 지울 수 있는 수가 있음을 보장할 수 있다.

 출력
 재민이가 최종적으로 적어 낸 수의 합을 출력한다. 최종적으로 적어낸 수의 합은 2^31-1보다 작거나 같은 정수이다.

 예제 입력				예제 출력
 4					0
 3
 0
 4
 0

 예제 입력				예제 출력
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
	int k; //k - 사용자 입력
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
  노드로 구현도 했음
  실행할 때는 문제가 없지만
  정답은 아님
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





