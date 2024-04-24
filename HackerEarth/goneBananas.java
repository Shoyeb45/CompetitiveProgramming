import java.util.*;

public class goneBananas {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        
        for(int i=1; i<=N; i++){
            int a = sc.nextInt();

            if(a == 2 || a == 3 || a == 1){
                System.out.println("No");
            }else{
                System.out.println("Yes");
            }
        }

        sc.close();
    }
    
}
