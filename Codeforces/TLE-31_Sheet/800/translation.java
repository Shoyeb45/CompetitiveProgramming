import java.util.Scanner;

public class translation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String t = sc.next(); 
        String s = sc.next();

        boolean ans = false;
        for(int i = 0; i<t.length(); i++){
            if(t.charAt(i) == s.charAt(s.length()-i-1)){
                ans = true;
            }else{
                ans = false;
                break;
            }
        } 

        if(ans)
        System.out.println("YES");
        else
        System.out.println("NO");
        
        sc.close();
    }
    
}
