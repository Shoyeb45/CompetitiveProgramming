import java.util.*;

public class AlmostPrime {
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
        int count=0;

        for(int i=4 ; i<=n ; i++){
            if(isPrime(i)){
                
            }else{
                int cnt = 0;
                for(int j=2 ; j<i ; j++){
                    
                    if(isPrime(j)){
                        if(i % j == 0){
                            cnt++;
                        }
                    }                    
                }
                if(cnt == 2){
                    count++;
                }
            }
        }
        System.out.println(count);
 
        sc.close();
    }
}
