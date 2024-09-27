import java.util.Scanner;

public class tram {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] res = new int[n];

        int sum = 0;
        for(int i=0 ; i<n ; i++){
            int a,b;
            a = sc.nextInt();
            b = sc.nextInt();

            sum = (sum - a) + b;

            res[i] = sum;

        }

        int max = res[0];
        for(int i=0; i<n; i++){
            if(res[i] >= max){
                max = res[i];
            }
        }

        System.out.print(max);
        sc.close();
    }
    
}
