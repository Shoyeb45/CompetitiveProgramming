import java.util.Scanner;

public class sherlockAndGf {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean[] isPrime = new boolean[n+2];

        for(int i=2; i<n+2 ;i++){
            isPrime[i] = true;
        }
        isPrime[0] = false; isPrime[1]= false;

        for(int i=2 ; (long)i*i<=n+1 ; i++){
            if(isPrime[i] ){
                for(int j=2*i; j<=n+1 ; j=j+i){
                    isPrime[j] = false;
                }
            }
        }

        if(n == 1 || n == 2)
        System.out.println(1);
        else
        System.out.println(2);
        for(int i=2; i<=n+1 ; i++){
            if(isPrime[i])
            System.out.print(1+" ");
            else
            System.out.print(2+" ");
        }

        

    }
    
}
