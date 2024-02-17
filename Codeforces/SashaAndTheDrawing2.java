import java.util.*;

public class SashaAndTheDrawing2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int color = 0;
            if(k <= 4 * (n-1))  color = (k + 1)/2;
            else {
                color = 2 * (n - 1);
                if(k - (4*n - 4)  == 2)    color += 2;
                if(k - (4*n - 4)  == 1)    color += 1;
            }
            System.out.println(color);
        }
        sc.close();
    }
}
