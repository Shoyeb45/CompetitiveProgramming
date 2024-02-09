import java.util.Scanner;

public class goodPairs {
    public static int max(int[] a, int l){
        int temp = a[0];
        for(int i = 0; i<=l-1; i++){
            if(a[i] > temp)
            temp = a[i];
        }
        return temp;
    }
    public static int min(int[] a, int l){
        int temp = a[0];

        for(int i = 0; i<=l-1; i++){
            if(a[i] < temp)
            temp = a[i];
        }
        return temp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int i=1; i<=t; i++){
           
                int n = sc.nextInt();
                int[] a = new int[n];
        
                for(int j=0; j<n ; j++){
                    a[j] = sc.nextInt();
                }
                int Max = max(a, n);
                int Min = min(a, n);
                int iMax = 0;
                int iMin = 0;
                for(int k = 0, p = n-1; k<=n-1 ;k++, p--){
                    if(Max == a[k])
                    iMax = k;
                    if(Min == a[p])
                    iMin = p;
                }
                System.out.print((iMax+1)+" "+(iMin+1)+"\n");
        }
    sc.close();
    }
    
}
