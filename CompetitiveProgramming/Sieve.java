package CompetitiveProgramming;
import java.util.*;

public class Sieve {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean[] isPrime = new boolean[n+1];

        for(int i=0; i<n+1 ;i++){
            isPrime[i] = true;
        }

        for(int i=2 ; i<=n ; i++){
            if(isPrime[i] == true){
                for(int j=2*i; j<=n ; j=j+i){
                    isPrime[j] = false;
                }
            }
        }

        for(int i=2 ; i<n ; i++){
            if(isPrime[i] == true)
            System.out.print(i+" ");
        }
        sc.close();
    }
}
