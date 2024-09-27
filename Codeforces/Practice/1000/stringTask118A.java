import java.util.*;

public class stringTask118A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        StringBuilder result = new StringBuilder(s);
       

        for(int i=0, j=0 ; i<s.length() ; i++, j++){
            if(s.charAt(i) == 'a' || s.charAt(i) == 'A' || s.charAt(i) == 'e' || s.charAt(i) == 'E'|| s.charAt(i) == 'i' || s.charAt(i) == 'I'|| s.charAt(i) == 'o' || s.charAt(i) == 'O' || s.charAt(i) == 'u' || s.charAt(i) == 'U' || s.charAt(i) == 'y' || s.charAt(i) == 'Y'){
                result.delete(j, j+1);
                j--;
            }else{
            if(s.charAt(i) >= 65 && s.charAt(i) <=90){
                result.setCharAt(j, (char)((int)result.charAt(j)+32));
                result.insert(j, '.');
            }else
            result.insert(j, '.');
            j++;
            }
        }

        
        System.out.println(result);
        
sc.close();
        


    }
    
}
