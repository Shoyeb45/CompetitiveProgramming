
import java.util.Scanner;

public class q8 {
    public static int decToBinary(int n){
        if(n == 0)
        return 0;

        return ((n % 2) + 10 * decToBinary(n/2));
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.println(decToBinary(n));
        
        
        sc.close();
    }
}
