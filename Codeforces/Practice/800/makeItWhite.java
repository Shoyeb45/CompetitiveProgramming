import java.util.*;

public class makeItWhite {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int i = 1; i<=t; i++){
            int l = sc.nextInt();
            String s = sc.next();

            int indStrtB = 0;
            int indEndB = 0;

            for(int j = 0; j<=s.length()-1 ; j++){
                if(s.charAt(j) == 'B'){
                indStrtB = j;
                break;
            }
            }
            for(int j = s.length()-1; j >= 0 ; j--){
                if(s.charAt(j) == 'B'){
                indEndB = j;
                break;
            }
            }
            if(l == 1 && s.charAt(0) == 'W')
            System.out.println(0);
            else
            System.out.println(indEndB - indStrtB + 1);
        }
        sc.close();
    }
}
