import java.util.*;

public class football96A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String position = sc.next();

        boolean ans = false;
        for(int i=0 ; i<position.length()-1 ; i++){
            int count1 = 0;
            int count2 = 0;

            if(position.charAt(i) == '1' && position.charAt(i) == position.charAt(i+1)){
                count1 = 1;
                for(int j = i+1 ; j<position.length() ; j++){
                    if(position.charAt(j) == '1' && position.charAt(i) == position.charAt(j))
                    count1++;
                    else
                    break;
                }
            }
            if(position.charAt(i) == '0' && position.charAt(i) == position.charAt(i+1)){
                count2 = 1;
                for(int j = i+1 ; j<position.length() ; j++){
                    if(position.charAt(j) == '0' && position.charAt(i) == position.charAt(j) )
                    count2++;
                    else
                    break;
                }
            }

            if(count1 >= 7 || count2 >=7)
            ans = true;
            else
            ans = false;
        
        }
        
        if(ans)
        System.out.println("YES");
        else
        System.out.println("NO");
        
        sc.close();
    }
}
