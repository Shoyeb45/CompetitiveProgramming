import java.util.*;

public class primeFactorization {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] leastDivisor = new int[n+1];
        for(int i=2 ; i<=n ; i++){
            leastDivisor[i] = i;
        }

        for(int i=2; i<=n ; i++){
            if(leastDivisor[i] == i && (long)i*i <= n){
                for(int j = i*i ; j<=n ; j+=i){
                    if(leastDivisor[j] == j){
                        leastDivisor[j] = i;
                    }
                }
            }
        }

        for(int i=n ; i != 1 ;){
            if(leastDivisor[i] == i)
            System.out.println(leastDivisor[i]);
            else
            System.out.print(leastDivisor[i]+"*");
            i /= leastDivisor[i]; 
        }
        sc.close();
    }
}
