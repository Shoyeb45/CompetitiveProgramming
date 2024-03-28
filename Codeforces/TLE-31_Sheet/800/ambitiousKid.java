import java.util.Scanner;

public class ambitiousKid {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int smallestPos = Integer.MAX_VALUE;

        for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            a[i] = Math.abs(a[i]);
            if(a[i] >= 0 && a[i] <= smallestPos) {
                smallestPos = a[i];
            }
            
        }

        System.out.println(smallestPos);
    }
}