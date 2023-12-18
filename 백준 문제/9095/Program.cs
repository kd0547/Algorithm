
using System.Runtime.CompilerServices;
using System.Runtime.Intrinsics.Arm;

public class Program
{
    

    public static void Main()
    {
        int[] dp = new int[11] { 1, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0 };

        int t = int.Parse(Console.ReadLine());
        int[] n = new int[t];
        
        for(int i = 3;i < dp.Length;i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        for (int i = 0; i < t; i++) 
        {
            n[i] = int.Parse(Console.ReadLine());
        }

        for(int i = 0; i < n.Length ; i++) 
        {
            Console.WriteLine(dp[n[i]-1]);
        }

    }

}