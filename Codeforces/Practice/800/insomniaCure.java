import java.util.Scanner;

public class insomniaCure {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int l = sc.nextInt();
        int m = sc.nextInt();
        int n = sc.nextInt();

        int d = sc.nextInt();

        boolean[] count = new boolean[d+1];

        for(int i=1; i<d+1 ; i++){
            count[i] = false;
        }

        for(int i=1 ; i<d+1 ; i++){
            if(i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
                count[i] = true;
        }

        int sum = 0;

        for(int i=1 ; i<=d ; i++){
            if(count[i] == true)
            sum++;
        }
        System.out.println(sum);
        sc.close();
    }
    
}
