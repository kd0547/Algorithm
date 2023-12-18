/*

  문제
  N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오

  입력
  첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.

  출력
  첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다

예제 입력       예제 출력
10              1
5               1
2               2
3               2
1               3
4               3
2               4
3               5
5               5
1               7
7


*************************************************************************************
계수정렬을 이용해 푸는 문제

참고
https://www.zerocho.com/category/Algorithm/post/58006da88475ed00152d6c4b

https://bowbowbow.tistory.com/8

두 사이트를 참고해 풀었음

*/


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

