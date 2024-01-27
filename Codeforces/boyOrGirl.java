import java.util.*;

public class boyOrGirl {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String x = sc.nextLine();
    int count = x.length();
        for(int i=0; i<x.length()-1 ; i++){
            for(int j=i+1 ; j<x.length() ; j++){
                if(x.charAt(i) == x.charAt(j)){
                   count = count-1;
                   break;
                }
            }   
        }

        if(count % 2 == 0)
        System.out.println("CHAT WITH HER!");
        else
        System.out.println("IGNORE HIM!");

        sc.close();
    }
}
