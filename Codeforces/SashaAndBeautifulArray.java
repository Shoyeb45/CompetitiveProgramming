import java.util.Arrays;
import java.util.Scanner;

public class SashaAndBeautifulArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for(int i=0; i<=n-1; i++)   arr[i] = sc.nextInt();  

            Arrays.sort(arr);
            System.out.println(arr[n-1] - arr[0]);
        }
    }
}
