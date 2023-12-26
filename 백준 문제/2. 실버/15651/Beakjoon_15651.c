#include <stdio.h>

int n, m;
int arr[10];

void func(int r)
{

    if (r == m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        arr[r] = i;

        func(r + 1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    func(0);

    return 0;
}