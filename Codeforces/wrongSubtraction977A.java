import java.util.*;

public class wrongSubtraction977A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        for(int i=1 ; i<=k ; i++){
            
            if(n % 10 != 0){
                n--;
            }else{
                n /= 10;
            }
        }
        System.out.println(n);
        sc.close();
    }
}
