#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define LEN 51
#define adj 5



void adjCabbage();
int X_plus(int row, int col);
int X_minus(int row, int col);
int Y_plus(int row, int col);
int Y_minus(int row, int col);
int calVertex(int row, int col, int M);
int** vertex(int size);
void adjvertex(int** vertex, int vertexSize);
//int* visit(int size);
int solution();
void Enqueue(int val);
int Dequeue();
void bfs(int v);
void clear();



int queue[LEN * LEN];
int field[LEN][LEN];

//int** adjField = NULL;
int adjField[(LEN * LEN)+1][adj];
int visited[LEN * LEN] = { 0, };

int front = 0;
int rear = 0;
int isEmpty = 0;

int T;
int M, N, K; 
// N * M
int size = 0;


int test();




int main()
{
	//https://www.acmicpc.net/problem/1012
	
	scanf_s("%d", &T);

	int* result = (int*)malloc(sizeof(int) * T);

	for (int j = 0; j < T; j++)
	{
		scanf_s("%d %d %d", &M, &N, &K);
		size = M * N;

		for (int i = 0; i < LEN * LEN; i++)
		{
			for (int z = 0; z < adj; z++)
			{
				adjField[i][z] = -1;
			}
		}

		//adjField = vertex(size);
		//adjvertex(adjField, size);

		//test();


		for (int i = 0; i < K; i++)
		{
			//m ,n
			int x, y;
			scanf_s("%d %d", &x, &y);
			field[x][y] = 1;
		}

		adjCabbage();
		int p = solution();

		result[j] = p;

		//printf_s("%d\n", p);
		clear();


	}

	for (int i = 0; i < T; i++)
	{
		printf_s("%d\n", result[i]);
	}



	return 0;
}
int test()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N;  j++)
		{
			field[i][j] = 1;
		}
	}
}



int solution()
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < adj; j++)
		{
			int a = adjField[i][j];
			if (adjField[i][j] != -1 && visited[a] != 1)
			{
				bfs(i);
				count++;
			}
		}
	}

	return count;
}

void bfs(int v)
{
	int i = 1;

	visited[v] = 1;

	Enqueue(v);

	while (isEmpty != 0)
	{
		v = Dequeue();

		for (i = 0; i < adj; i++)
		{
			int a = adjField[v][i];
			if (adjField[v][i] != -1 && visited[a] != 1)
			{
				visited[a] = 1;
				Enqueue(adjField[v][i]);
			}
		}

	}

	

}


void Enqueue(int val)
{
	if (queue[rear] == ((LEN * LEN) - 1))
	{
		rear = 0;

		queue[rear] = val;
	}
	else
	{
		queue[rear] = val;
	}
	rear++;
	isEmpty++;
	
}

int Dequeue()
{
	int position = queue[front];

	if (front == ((LEN * LEN) - 1))
	{
		front = 0;
	}
	else
	{
		front++;
	}

	isEmpty--;


	return position;
} 

int** vertex(int size)
{
	return (int**)malloc(sizeof(int*) * size);
}

void adjvertex(int** vertex, int vertexSize)
{
	for (int i = 0; i < vertexSize; i++)
	{
		*(vertex + i) = (int*)malloc(sizeof(int) * adj);
	}

	for (int i = 0; i < vertexSize; i++)
	{
		for (int j = 0; j < adj; j++)
		{
			adjField[i][j] = -1;
		}
	}
}


//인접리스트 생성
void adjCabbage()
{
	int size = N;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (field[i][j] == 1) {
				
				int temp = calVertex(i, j, size);
				adjField[temp][0] = temp;
				adjField[temp][1] = X_plus(i, j);
				adjField[temp][2] = X_minus(i, j);

				adjField[temp][3] = Y_plus(i, j);
				adjField[temp][4] = Y_minus(i, j);
			}
		}
	}

}
int X_plus(int m, int n)
{
	if (n < N - 1)
	{
		if (field[m][n + 1] == 1)
		{
			return calVertex(m, n + 1, N);
		}
	}
	

	return -1;
}


int X_minus(int m, int n)
{
	if (n > 0)
	{
		if (field[m][n - 1] == 1)
		{
			return calVertex(m, n - 1, N);
		}	
	}
	
	return -1;
}

int Y_plus(int m, int n)
{
	if (m < (M - 1))
	{
		if (field[m + 1][n] == 1)
		{
			return calVertex(m + 1, n, N);
		}
	}
	

	return -1;
}

int Y_minus(int m, int n)
{
	if (m > 0)
	{
		if (field[m - 1][n] == 1)
		{
			return calVertex(m - 1,n , N);
		}
	}
	
	return -1;
}




int calVertex(int m, int n,int s)
{
	return  n + (m * s);
}

void clear()
{
	/*for (int i = 0; i < size - 1; i++)
	{
		free(*(adjField + i));
	}
	free(adjField);*/

	//queue 초기화 
	if (front != 0 || rear != 0)
	{
		front = 0;
		rear = 0;
	}
	for (int i = 0; i < LEN * LEN; i++)
	{
		visited[i] = 0;
	}

	//필드 초기화 
	for (int i = 0; i < LEN; i++)
	{
		for (int j = 0; j < LEN; j++)
		{
			field[i][j] = 0;
		}
	}
}