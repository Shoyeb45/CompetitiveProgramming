import java.util.Scanner;

public class BeautifulMatrix2 {
    public static int absolute(int a, int b) {
        int c = a -b;
        if(c > 0) return c;

        return -1*c;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] matrix = new int[5][5];

        for(int i=0; i<=4; i++)
            for(int j=0; j<=4; j++) matrix[i][j] = sc.nextInt();
            
            int row = 0, column = 0 ;
            for(int i=0; i<=4; i++) {
                for(int j=0; j<=4; j++) { 
                    if(matrix[i][j] == 1) {
                        row = i;
                        column = j;
                    }
                }
            }
            System.out.println(absolute(2, row) + absolute(2, column));

        sc.close();
    }
}
