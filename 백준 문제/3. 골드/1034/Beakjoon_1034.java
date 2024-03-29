package study;
import java.util.Scanner;

public class Beakjoon_1034 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/* 
		  문제 출처 : https://www.acmicpc.net/problem/1034

		  문제
		  지민이는 각 칸마다 (1×1크기의 정사각형) 램프가 들어있는 직사각형 모양의 탁자를 샀다. 모든 램프는 켜져있거나 꺼져있다. 각 열의 아래에는 스위치가 하나씩 달려있는데, 
		  이 스위치를 누를 때마다 그 열에 있는 램프의 상태가 바뀐다. 켜져있는 램프는 꺼지고, 꺼져있는 램프는 켜진다)
		  만약 어떤 행에 있는 램프가 모두 켜져있을 때, 그 행이 켜져있다고 말한다. 지민이는 스위치를 K번 누를 것이다. 서로다른 스위치 K개를 누르지 않아도 된다. 
		  지민이는 스위치를 K번 눌러서 켜져있는 행을 최대로 하려고 한다.
		  지민이의 탁자에 있는 램프의 상태와 K가 주어졌을 때, 스위치를 K번 누른 후에 켜져있는 행의 최댓값을 구하는 프로그램을 작성하시오.
		  
		  
		  입력
		  첫째 줄에 N과 M이 주어진다. N은 행의 개수이고, M은 열의 개수이다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 램프의 상태가 주어진다. 
		  1이 켜져있는 상태이고, 0이 꺼져있는 상태이다. 마지막 줄에는 K가 주어진다.  K는 1,000보다 작거나 같은 자연수 또는 0이다.
		  
		  출력
		  첫째 줄에 문제의 정답을 출력한다.
		  
		  
		  예제 입력                 예제 출력 
		  3 2                       2
		  01
		  10
		  10
		  1
		  
		  예제 입력                 예제 출력
		  1 6                       0
		  101010
		  2

		  예제 입력                 예제 출력
		  14 3                      4
		  001
		  101
		  001
		  000
		  111
		  001
		  101
		  111
		  110
		  000
		  111
		  010
		  110
		  001
		  6
		  
		  
		  ************************************************************************************************************
		  문제의 핵심
		  
		  1. 꺼져있는 램프의 수를 OFFL이라고 했을 때 K보다 작거나 같아야한다. 
		      > OFFL <= K
		      
		  2. 꺼져있는 램프의 수 OFFL과 스위치를 K번 누르는 횟수(홀,짝) 같아야 한다. 
		      > OFFL % 2 == k% 2 
		  
		  
		  
		  
		  ************************************************************************************************************


		*/

		
		Scanner sc = new Scanner(System.in);
		
		int N;
		int M;
		
		// K번 누름 
		int K;
		
		N = sc.nextInt();
		M= sc.nextInt();
		sc.nextLine();
		int MAX = 0;
		int[][] arry = new int[N][M];
		String[] S = new String[N];
		
		for(int i = 0; i < N;i++) {
			S[i] = sc.nextLine();
			for(int j=0; j < M;j++) {
				arry[i][j] =  Integer.parseInt(S[i].charAt(j)+"");
			}
		}
		K = sc.nextInt();
		
		for(int i = 0; i < N;i++) {
			int count = 0;	
			//해당 열이 0인지 1인지 구분 
			for(int j=0; j < M;j++) {
				if(arry[i][j] == 0) {count++;}
			}
      
			if( (K%2 == count%2) && count <= K ) {
				int c = 0;
				for(int j=0;j<N;j++) {
					if(S[i].equals(S[j])) {
						
						c++;
					}
				}
				if(MAX < c) {
					MAX = c;
				}
			}
		}
		System.out.println(MAX);

				

	}

}
