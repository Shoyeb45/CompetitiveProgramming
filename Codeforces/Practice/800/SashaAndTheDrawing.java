import java.util.Scanner;

public class SashaAndTheDrawing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int sum = 0, color = 0;
            for(@SuppressWarnings("unused")
            int i=1; ; i++) {
                if(sum >= k)    break;
                if(color < 2 * (n - 1)) {
                    sum += 2;
                    color++; 
                    
                } else {
                    sum += 1;
                    color++;
                }
            }
            System.out.println(color);
        }
        sc.close();
    }
}
