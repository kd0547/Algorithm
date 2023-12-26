#include <stdio.h>

int n, m;
int arr[10];
int isused[10];

void func(int k)
{
    if (k == m)
    {
        int i = 0;
        while (i < (m - 1))
        {
            if (arr[i] < arr[i + 1])
            {
            }
            else
            {
                return;
            }
            i++;
        }
        for (int i = 0; i < m; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isused[i]) // 1이면 -> 0 , 0이면 -> 1,
        {

            arr[k] = i;
            isused[i] = 1; // 값이 들어갔으니 1을 넣는다
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    func(0);

    return 0;
}