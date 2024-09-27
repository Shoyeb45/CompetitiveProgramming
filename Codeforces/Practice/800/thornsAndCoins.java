import java.util.*;
public class thornsAndCoins {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            String path = sc.next();

            int coins = 0;

            for(int i=1; i<n; i++) {

                if(path.charAt(i) == '@') {
                    coins++;
                } 
                else if( i+1 != n && path.charAt(i) == '*' && path.charAt(i+1) == '*') {
                    break;
                }
                else if(  i+1 != n && path.charAt(i) == '*' && path.charAt(i+1) != '*' ) {
                    continue;
                } else if (path.charAt(i) == '.') {
                    continue;
                } 
                
                
            }   
            System.out.println(coins);
        }
        sc.close();
    }
}