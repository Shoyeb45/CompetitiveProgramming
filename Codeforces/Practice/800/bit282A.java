import java.util.*;

public class bit282A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = 0;

        for(int i=1; i<=n ; i++){
            String operation = sc.next();

            if(operation.charAt(0) == '+' || operation.charAt(1) == '+')
            x++;
            else
            x--;
             }

             System.out.println(x);
             sc.close();
    }
    
}
