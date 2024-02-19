import java.util.Scanner;

public class VladAndSumOfDigit {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();

                int sum = 0;
            if(n <= 9) {
                System.out.println(n * (n + 1) / 2);
            } else {
                    sum = 45;
                for(int i=10 ; i<=n; i++) {
                    int temp = i;
                    int digitSum = 0;
                    for(int k=temp; k>=1; k /= 10) {
                        digitSum += (k % 10);
                    }
                    sum += digitSum;  
                }
                System.out.println(sum);
            }
            
        }
        sc.close();
    }    
}


