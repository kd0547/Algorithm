import java.util.Scanner;

public class Beakjoon_1018 {
	
	static boolean board[][] ;
	static int min=64;

	public static void main(String[] args) {
		int N,M;
				
		Scanner scan = new Scanner(System.in);
		
		N = scan.nextInt();
		M = scan.nextInt();
		
		board = new boolean[N][M];
		
		
		for (int i = 0; i < N; i++) {
			String str = scan.next();
			
			for (int j = 0; j < M; j++) {
				if (str.charAt(j) == 'W') {
					board[i][j] = true;		// W일 때는 true 
				} else {
					board[i][j] = false;		// B일 때는 false
				}
 
			}
		}
		//start 함수 실행 중 
		//ArrayIndexOutOfBoundsException 예외가 발생하지 않게 
		// 값을 빼준다.
		for(int i = 0;i< N - 7;i++) {
			for(int j=0;j<M - 7;j++) {
				start2(i,j);
			}
		}
		System.out.println(min);
	}
	
	public static void start(int x,int y) {
		int count = 0;

		boolean TF = board[x][y];

		for(int i=x;i< x+8;i++) {
			for(int j=y;j< y+8;j++) {
				if(board[i][j] != TF) {
					count++;
				}
				//W -> B , B -> W
				TF = (!TF);
				
			}
			TF = !TF;
		}
		count = Math.min(count, (64 - count)); 
		
		min =  Math.min(min,count);
	}
	
	public static void start2(int x,int y) {
		int count = 0;
		//초기값을 저장
		boolean TF = board[x][y];
	
		for(int i = x;i<x+8;i++) {
			for(int j=y;j<y+8;j++) {
				
				//짝수번째 항은 초기값과 같고 홀수번째 항은 초기값과 다르다.
				if((i+j) % 2 == 0  ) {
					//true = W, false = B
					if(board[i][j] != TF) 
						count++;
				} else {
					//true = W, false = B
					if(board[i][j] == TF)
						count++;
					
				}
				
			}
			
		}
		count = Math.min(count, (64 - count)); 
		
		min =  Math.min(min,count);
		
		
		
	}

}
