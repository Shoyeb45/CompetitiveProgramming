import java.util.*;

public class panoramixPrediction {
    public static boolean isPrime(int a){
        boolean response = false;
               if( a == 1)
               response = false ; 
               else{
                int i=2;
                for(i=2 ; i*i<=a ; i++){
                    if(a % i == 0)
                    break;
                }

                if(i*i > a)
                response = true;
                else
                response = false;
               }

               return response;

    } 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); 
        int m = sc.nextInt();
int a = 0;

        for(int i=n+1 ; i<=m ; i++){
            if(isPrime(i)){
                a = i;
                break;
            }
        }
        
    if(a == m)
    System.out.println("YES");
    else
    System.out.println("NO");
        sc.close();
    }
    
}
