import java.util.Scanner;
import java.lang.Math;

public class TPrime {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int y = 10000000;
        boolean[] prime = new boolean[y+1];
        prime[0] = false; prime[1] = false;

        for(int i=2; i<=y ; i++){
            prime[i] = true;
        }

        for(int i=2; (long)i*i<=y ; i++){
            if(prime[i] && (long)i*i<=y){
                for(int j=i*i; j<=y ; j+=i){
                    prime[j] = false;
                }
            }
        }

        while (n-- != 0) {
            long x = sc.nextLong();
            long r = (long)Math.sqrt(x);

            if(prime[(int)r] && (long)r*r == x)
            System.out.println("YES");
            else
            System.out.println("NO"); 
        }

        
        sc.close();
    }
    
}
