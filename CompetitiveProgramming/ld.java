// Least Divisor

package CompetitiveProgramming;

import java.util.Scanner;

public class ld {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        int[] isPrime = new int[n+1];

        for(int i=1; i<=n ; i++){
            isPrime[i] = i;
        }

        for(int i=2; i<=n ; i++){
            if(isPrime[i] == i){
                for(int j=2*i ; j<=n ; j=j+i){
                   if(isPrime[j] == j){
                        isPrime[i] = i;                    
                   } 
                }
            }
            sc.close();
        }
    }
    
}
