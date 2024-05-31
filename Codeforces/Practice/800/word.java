import java.util.*;

public class word {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
int upperCase = 0, lowerCase = 0 ;

String answer = "";
        for(int i=0 ; i<s.length() ; i++){
            if(s.charAt(i) >= 'a' && s.charAt(i) <= 'z' ){
                lowerCase++;
            }else{
                upperCase++;
            }
        }
       if(lowerCase >= upperCase){
        answer = s.toLowerCase();
       }else{
        answer = s.toUpperCase();
       }

       System.out.println(answer);
       sc.close();
    }
}
