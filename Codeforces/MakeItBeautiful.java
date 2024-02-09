import java.util.Scanner;

public class MakeItBeautiful {
    public static void swap(int[] a, int i, int j){
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        for(int i = 1; i<=n; i++){
            int t = sc.nextInt();
            int[] a = new int[t];

            for(int j = 0; j<t; j++)
            a[j] = sc.nextInt();
            
            
            swap(a, 0, 1);
            
            swap(a, 0, t-1);
            
            if(a[0] == a[1])
            System.out.println("NO");
            else{
                System.out.println("YES");
                for(int k = 0; k<t; k++){
                    System.out.print(a[k]+" ");
                }
                System.out.println();
            }
            sc.close();
        }
    }
    
}
