import java.util.*;

public class petyaString {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String gift1 = sc.nextLine();
        String gift2 = sc.nextLine();
boolean ans = false;
        for(int i=0 ; i<gift1.length() ; i++){
            if(gift1.toLowerCase().charAt(i) == gift2.toLowerCase().charAt(i) ){
             ans = true;
            }else if(gift1.toLowerCase().charAt(i) < gift2.toLowerCase().charAt(i)){
                System.out.println(-1);
                ans = false;
                break;
            }else{
                System.out.println(1);
                ans = false;
                break;
            }
        }

        if(ans)
        System.out.println(0);

        sc.close();
        
        
    }
}
