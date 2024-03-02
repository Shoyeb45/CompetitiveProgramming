import java.util.Scanner;

public class doors {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        boolean[] door = new boolean[n+1];

        for(int i=1; i<=n; i++) door[i] = false;
        
        for (int i=1; i<=n; i++) {
            for(int j=i; j<=n; j += i) {
                if(door[j])    door[j] = false;
                else    door[j] = true;
            }
        }
        
        for(int i=1; i<=n; i++) {
            if(door[i]) {
                System.out.println("Door " + i + " is open."); 
            } else {
                System.out.println("Door " + i + " is closed.");
            }
        }
        sc.close();
    }
}
