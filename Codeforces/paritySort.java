import java.util.Arrays;
import java.util.Scanner;

public class paritySort {
    public static boolean isSorted(int[] a, int init ,int len) {
        boolean o = true;

        for(int i=init; i<len-1; i++) {
            if(a[i] <= a[i+1])
                o = true;
            else {
                o = false;
                break;
            }
        }
        return o;
    }

    public static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            int[] a = new int[n];

            for(int i=0; i<=n-1; i++)
                a[i] = sc.nextInt();
                
                int[] sorted = new int[n];
                for(int i=0; i<=n-1; i++)
                    sorted[i] = a[i];
            Arrays.sort(sorted);

            int oddNo = 0, evenNo = 0;
            for(int i=0 ; i<=n-1; i++){
                if(a[i] % 2 == 0)
                    evenNo += 1;
                else
                    oddNo +=1;
            }
            
            if (isSorted(a, 0, n))
                System.out.println("YES");
            else if( (n != 1) && (evenNo == 1 || oddNo == 1)) 
                System.out.println("NO");
            else if (oddNo == n || evenNo == n )
                System.out.println("YES") ;
            else {
                for(int i=0; i<=n-1; i++) {
                    if( (a[i] != sorted[i]) && ((a[i] % 2 == 0 && sorted[i] % 2 == 0) || (a[i] % 2 != 0 && sorted[i] % 2 != 0))) {
                            int idx = 0;
                            if(i+1 != n) {
                        for(int j=i+1; j<=n-1; j++) {
                            if(a[j] == sorted[i]){
                                idx = j;
                                break;
                            }
                        }
                        swap(a, i, idx);
                    }
                }
                }

                if(isSorted(a, 0, n)) 
                    System.out.println("YES");
                else
                    System.out.println("NO");
            }
            
                
        }
    sc.close();
    }
}
