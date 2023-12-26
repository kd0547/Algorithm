#include <stdio.h>
#include <stdbool.h>

int selfcheck(int n)
{
    int sum = n;
    while (n != 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

int main()
{
    bool arr[10001] = {false};
    int idx = 0;
    for (int i = 1; i < 10001; i++)
    {
        idx = selfcheck(i);
        arr[idx] = true;
        if (arr[i] == false)
        {
            printf("%d \n", i);
        }
    }

    return 0;
}
