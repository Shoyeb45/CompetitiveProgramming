package ClassWork.Recursion;

import java.util.Scanner;

public class q10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        char[] a = s.toCharArray();
        int len = 0;
        for(char c : a){
            len++;
        }
        System.out.println(len);
        sc.close();
    }
}
