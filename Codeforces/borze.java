import java.util.*;

public class borze {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String borzeCode = sc.next();
        char[] borze = borzeCode.toCharArray(); 
    
  

        for(int i=0 ; i<borzeCode.length(); i++){
            if( borze[i] == '.'){
                System.out.print(0);
            }else if( borze[i] == '-' ){
                if( borze[i+1] == '.' ){
                    borze[i+1] = 0 ; 
                System.out.print(1);
            }else if( borze[i] == '-'){
                if( borze[i] == '-' ){
                    borze[i+1] = 0 ;
                    System.out.print(2);
                }
            }
            
        }
    }
    sc.close(); 
}
}
