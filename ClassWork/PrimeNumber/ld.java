package PrimeNumber;

// Least Divisor



import java.util.Scanner;

public class ld {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        int[] isPrime = new int[n+1];

        for(int i=2; i<=n ; i++){
            isPrime[i] = i;
        }

        for(int i=2; i<=n ; i++){
            if(isPrime[i] == i && (long)i*i<=n){
                for(int j=i*i ; j<=n ; j=j+i){
                   if(isPrime[j] == j){
                        isPrime[j] = i;                    
                   } 
                }
            }

           
        }
        for(int i=2 ; i<n+1 ; i++){
            System.out.println("Least divisor of "+i+" " + isPrime[i]);
        }
        sc.close();
    }
    
}
