package ClassWork.Recursion;

import java.util.Scanner;

public class q12 {
        public static int sumDigit(int n){
            if(n < 1 && n >= 0){
                return (n % 10);
            }
            if(n > -1 && n <= 0){
                return (n % 10) * -1;
            }

            if(n > 0)
            return (n % 10) + sumDigit(n/10);

            return ((n % 10) * -1) + sumDigit(n/10);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // if(n > 0)
        // System.out.println(sumDigit(n));
        // else
        // System.out.println(sumDigit(-1*n));
        
        System.out.println(sumDigit(n));
        sc.close();
    }
}
