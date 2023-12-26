#include<stdio.h>
#include<stdlib.h>

int M[10001] = { 0 };

int main() {
    int N;
    int input;
    scanf_s("%d", &N);



    for (int i = 0; i < N; i++)
    {
        scanf_s("%d", &input);
        M[input]++;
    }

    for (int i = 0; i < 10001; i++)
    {
        if (M[i] != 0)
        {
            for (int j = 0; j < M[i]; j++)
            {
                printf_s("%d\n", i);
            }
        }
    }

    return 0;
}

