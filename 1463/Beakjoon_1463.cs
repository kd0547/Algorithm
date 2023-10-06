class Program
{

    static int[] DP = new int[1000001];

    static void Main()
    {
        string input = Console.ReadLine();
        int N = int.Parse(input);
        int i = 2;
        for (; i <= N; i++) 
        {
            //1을 뺏을 때 
            DP[i] = DP[i - 1] + 1;

            //2로 나누어지면 
            if(i % 2 == 0)
            {
                DP[i] = Math.Min(DP[i], DP[i/2] + 1);
            }

            //3으로 나누어지면 
            if(i % 3 == 0)
            {
                DP[i] = Math.Min(DP[i], DP[i / 3] + 1);
            }

        }
        Console.WriteLine(DP[i-1]);
    }
}








// 메모리 초과 코드
//class Program
//{

//    static void Main()
//    {
//        int i = 0;

//        string n = Console.ReadLine();
//        int x = int.Parse(n);

//        List<int[]> ary = new List<int[]>();
//        ary.Add(new int[1] { x});


//        while (true) 
//        {
//            int j = 0;

//            //배열 공간 추가 
//            int size = ary[i].Length * 3;
//            ary.Add(new int[size]);


//            while (j < ary[i].Length) 
//            {
//                if (ary[i][j] == 0)
//                {
//                    j++;
//                    continue;
//                }

//                if (ary[i][j] == 1)
//                {
//                    break;
//                }

//                if (ary[i][j] % 3 == 0)
//                {
//                    ary[i+1][j * 3] = ary[i][j] / 3;
//                }

//                if (ary[i][j] % 2 == 0)
//                {
//                    ary[i + 1][(j * 3)+1] = ary[i][j] / 2;
//                }

//                ary[i + 1][(j * 3) + 2] = ary[i][j] - 1;

//                j++;
//            }

//            if ((j < ary[i].Length - 1) && ary[i][j] == 1)
//            {
//                break;
//            }
//            i++;



//        }
//        Console.WriteLine(i);

//    }
//}
