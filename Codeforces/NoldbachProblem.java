import java.util.Scanner;

public class NoldbachProblem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        boolean[] prime = new boolean[n+1];
        prime[0] = false; prime[1] = false;
        for(int i=2 ; i<=n ; i++){
            prime[i] = true;
        }

        for(int i=2 ; i*i<=n; i++){
            if(prime[i]){
                for(int j = i*i ; j<=n; j+=i)
                prime[j] = false;
            }
        }
        
        int count = 0;

        int[] newPrime = new int[n/2];
        for(int i=2, j = 0; i<=n ; i++){
            if(prime[i]){
                newPrime[j] = i;
                j++;
            }
        }
        
        for(int i=5; i<newPrime.length ; i++){
            if(newPrime[i] == 0)
            break;
            else{
                for(int j = 0; j < i-1 ; j++){
                    if(newPrime[j]+newPrime[j+1]+1 == newPrime[i])
                    count++;
                }

            }

        }
        if(count >= k)
        System.out.println("YES");
        else
        System.out.println("NO");

        sc.close();
    }
    
}
