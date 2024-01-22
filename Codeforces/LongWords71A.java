import java.util.*;

public class LongWords71A {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
 int n = sc.nextInt();
 String[] words = new String[n];

 for(int i=0 ;i<n ; i++){
    words[i] = sc.next();
 }

 for(int i=0 ;i<n ; i++){
    if(words[i].length() <= 10)
    System.out.println(words[i]);
    else{
        String abbr = words[i].charAt(0) + Integer.toString(words[i].length()-2) + words[i].charAt(words[i].length()-1);
        System.out.println(abbr);
    } 
}



        sc.close();
    }
}
