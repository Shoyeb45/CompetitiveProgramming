import java.util.Scanner;

public class LRRemainders {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] num = new int[n];

            for(int i=0; i<=n-1; i++)  num[i] = sc.nextInt();

            String cmnd = sc.next(); 

                long mult = 1;
            for(int i=0; i<n; i++)  mult *= (long)(num[i]);

                int leftInd = 0, rightInd = n-1;
                System.out.print((long)(mult % m) +" ");

            for(int i=0; i<n-1; i++) {
                if(cmnd.charAt(i) == 'L') {
                    mult /= (long)(num[leftInd]);
                    leftInd++;
                    System.out.print((long)(mult % m) + " ");
                } else {
                    mult /= (long)(num[rightInd]);
                    rightInd--;
                    System.out.print((long)(mult % m) + " ");
                }
            }
            System.out.println();
        }
        sc.close();
    }   
}
