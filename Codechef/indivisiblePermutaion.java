package Codechef;
import java.util.*;

public class indivisiblePermutaion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for(int i = 1; i<=n ; i++){
            int a = sc.nextInt();

            System.out.print(2+" ");
            for(int j=1; j<=a-2 ; j++){
                System.out.print(j+2+" ");
            }
            System.out.print(1+" ");
            System.out.println();
        }
        sc.close();
    }
}
