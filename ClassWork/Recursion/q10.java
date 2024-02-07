package ClassWork.Recursion;

import java.util.Scanner;

public class q10 {
    public static int strlen(String s){
        char[] a = s.toCharArray();
        int len = 0;
        for(char c : a){
            len++;
        }
        return len;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        
        System.out.println(strlen(s));
        sc.close();
    }
}
