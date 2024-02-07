package ClassWork;

import java.util.Scanner;
import java.lang.Math;

public class segmentedSieve {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long L = sc.nextLong();
        long R = sc.nextLong();
        int n =(int) Math.sqrt((double)R);

        // Array for 2 to root(R)
        boolean[] isPrime = new boolean[n+1];
        isPrime[0] = false; isPrime[1] = false;
        for(int i=2; i<=n ; i++){
            isPrime[i] = true;
        }
        //Checking prime between 2 to root(R)

        for(int i=2; i*i<=n ; i++){
            if(isPrime[i]){
                for(int j = i*i ; j<=n ; j+=i){
                    isPrime[j] = false;
                }
            }
        }

        // Checking the prime number between L to R
        boolean[] primeBetween = new boolean[(int)(R-L)];
        for(int i=0; i<=(int)(R-L-1); i++){
            primeBetween[i] = true;
        }
        for(int i = 2; i<=n ; i++){
            if(isPrime[i]){
                for(int j = (int)((L+i-1)/i) * i ; j<=(int)(R-1) ; j+=i){
                    primeBetween[(int)(j-L)] = false;
                }
            }
        }

        for(int i=0; i<=(int)(R-L-1) ; i++){
            if(primeBetween[i]){
                System.out.print( (i+L) + " " );
            }
        }

        sc.close();

    }
}
