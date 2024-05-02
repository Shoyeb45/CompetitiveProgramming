import java.util.Scanner;

public class stringRev {
    public static String Reverse(String s) {
        String str = ""; 
        for(int i = s.length() - 1; i >= 0; i--)    str = str + s.charAt(i);
        return str;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String[] arr = s.split(" ");
        String str = "";
        for(String i : arr) {
            str = str + Reverse(i) + " ";
        } 
        System.out.println(str);
        sc.close();
    }
}
