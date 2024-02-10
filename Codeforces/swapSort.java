import java.util.*;

public class swapSort {
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
        int n = sc.nextInt();
        int[] a = new int[n];

        for(int i=0; i<=n-1; i++)
            a[i] = sc.nextInt();
    
            boolean ans = isSorted(a, 0, n);
            if(ans)
                System.out.println(0);
            else {
                int Swaps = 0;
                int[] sorted = new int[n];
                for(int i = 0; i<=n-1; i++)
                    sorted[i] = a[i];

                Arrays.sort(sorted);
                int[][] pairs = new int[2][n];

                for(int i=0; i<=n-1; i++){
                    if( a[i] == sorted[i])
                        continue;
                    else {
                        int idx = 0;
                        for(int j=i+1; j<=n-1; j++){
                            if(a[j] == sorted[i])
                                idx = j;
                        }
                            swap(a, i, idx);
                        pairs[0][Swaps] = i;
                        pairs[1][Swaps] = idx;
                        Swaps++;

                        if(isSorted(a, i+1, n)){
                            break;
                        }

                    }
                }
                
                System.out.print(Swaps);
                
                for(int i=0; i<=Swaps-1; i++) 
                    System.out.print("\n"+pairs[0][i] + " " + pairs[1][i]);

            }
    sc.close();    
    }
}
