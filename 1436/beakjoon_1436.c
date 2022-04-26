/*
  문제
  666은 종말을 나타내는 숫자라고 한다. 따라서, 많은 블록버스터 영화에서는 666이 들어간 제목을 많이 사용한다. 영화감독 숌은 세상의 종말 이라는 시리즈 영화의 감독이다.
  조지 루카스는 스타워즈를 만들 때, 스타워즈 1, 스타워즈 2, 스타워즈 3, 스타워즈 4, 스타워즈 5, 스타워즈 6과 같이 이름을 지었고,
  피터 잭슨은 반지의 제왕을 만들 때, 반지의 제왕 1, 반지의 제왕 2, 반지의 제왕 3과 같이 영화 제목을 지었다.
  하지만 숌은 자신이 조지 루카스와 피터 잭슨을 뛰어넘는다는 것을 보여주기 위해서 영화 제목을 좀 다르게 만들기로 했다.
  종말의 숫자란 어떤 수에 6이 적어도 3개이상 연속으로 들어가는 수를 말한다. 제일 작은 종말의 숫자는 666이고, 그 다음으로 큰 수는 1666, 2666, 3666, .... 과 같다.
  따라서, 숌은 첫 번째 영화의 제목은 세상의 종말 666, 두 번째 영화의 제목은 세상의 종말 1666 이렇게 이름을 지을 것이다.
  일반화해서 생각하면, N번째 영화의 제목은 세상의 종말 (N번째로 작은 종말의 숫자) 와 같다.
  숌이 만든 N번째 영화의 제목에 들어간 숫자를 출력하는 프로그램을 작성하시오. 숌은 이 시리즈를 항상 차례대로 만들고, 다른 영화는 만들지 않는다.

  입력
  첫째 줄에 숫자 N이 주어진다. N은 10,000보다 작거나 같은 자연수이다.

  출력
  첫째 줄에 N번째 영화의 제목에 들어간 수를 출력한다.

*/

#include<stdio.h>
#include<stdlib.h>

// 666 검사
int count(int a)
{

    while (a != 0)
    {
        if (a % 1000 == 666)
        {
            return 1;
        }
        else
            a = a / 10;
    }
    return 0;
}

int main()
{
    int n = 0; // 몇 번 째 값인지 검사 

    int a = 665; // 증가값
    int cnt = 1; // 666 3번이 나오면 증가 시킴 

    scanf_s("%d", &n);

    if (n > 10000)
        return 0;

    while (1)
    {
        if (count(a))
        {
            if (cnt == n)
            {
                printf_s("%d\n", a);
                return 0;
            }
            cnt++;
        }
        a++;

    }


    return 0;
}
