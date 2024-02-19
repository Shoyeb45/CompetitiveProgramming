import java.util.Scanner;

public class VladBestOfFive {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            String s = sc.next();
            int A = 0;
            int B = 0;

            for(int i=0; i<5; i++) {
                if(s.charAt(i) == 'A')
                    A++;
                else    
                    B++;
            }

            if(A > B)  
                System.out.println("A");
            else
                System.out.println("B");
        }
        sc.close();
    }
}
