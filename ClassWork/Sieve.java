package ClassWork;
import java.util.*;

public class Sieve {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        boolean[] isPrime = new boolean[(int)(n+1)];

        for(int i=0; (long)i<n+1 ;i++){
            isPrime[i] = true;
        }
        
        isPrime[0] = false; isPrime[1]= false;
        for(int i=2 ; (long)i*i<=n ; i++){
            if(isPrime[i] ){
                for(int j=2*i; j<=n ; j=j+i){
                    isPrime[j] = false;
                }
            }
        }

        for(int i=2 ; i<=n ; i++){
            if(isPrime[i] == true)
            System.out.print(i+" ");
        }
        sc.close();
    }
}
