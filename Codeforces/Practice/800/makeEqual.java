import java.util.Scanner;

public class makeEqual {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            int[] water = new int[n];

            for(int j=0; j<n; j++)  water[j] = sc.nextInt();
            
            int amt = 0;
            for(int j=0; j<n; j++)  amt += water[j];
            amt /= n;
            boolean ans1 = false;
            boolean ans2 = false;
            for(int i=0; i<n; i++) {
                if(water[i] >= amt) ans1 = true;
            }
            for(int i=(n/2)+1; i<n; i++) {
                if(water[i] <= amt) ans2 = true;
            }
            if(ans1 && ans2) System.out.println("Yes");
            else    System.out.println("No");
        }
        sc.close();
    }
}
