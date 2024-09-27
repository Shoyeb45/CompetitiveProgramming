import java.util.Scanner;

public class VladShapes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            
            int[] count = new int[n];

            for(int i=0; i<n; i++) {
                String grid = sc.next();
                int tempCount = 0;
                for(int j=0; j<n; j++) {
                    if(grid.charAt(j) == '1') {
                        tempCount++;
                    }
                }
                count[i] = tempCount;
            }
            boolean isTriangle = false;
            int j = 1;
            for(int i=0; i<n; i++) {
                if(count[i] != 0 && count[i] == 2 * j - 1) {
                    isTriangle = true;
                    j++;
                }
            }
            if(isTriangle) 
                System.out.println("TRIANGLE");
            else
                System.out.println("SQUARE");
        }
        sc.close();
    }
}
