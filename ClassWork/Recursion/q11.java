package ClassWork.Recursion;

import java.util.Scanner;

public class q11 {
    public static boolean isPalindrome(String s, int i, int strlen){
        if(i == strlen/2 && strlen % 2 !=0 ){
            return true;
        }

        if(i == strlen/2-1 && strlen % 2 ==0 && s.charAt(i) == s.charAt(i+1)){
            return true;
        }

        if(strlen % 2 != 0){
        if(s.charAt(i) == s.charAt(strlen-i-1)){
            return true && isPalindrome(s, i+1, strlen);
        }
    }else{
        if(s.charAt(i) == s.charAt(strlen-i-1)){
            return true && isPalindrome(s, i+1, strlen);
        }
    }

        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(isPalindrome(s, 0, s.length()));
        sc.close();
    }
    
}
