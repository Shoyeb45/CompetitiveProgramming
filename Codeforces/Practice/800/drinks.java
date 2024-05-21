import java.util.Scanner;

public class drinks {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] p = new int[n];
        for(int i=0 ; i<n ; i++){
            p[i] = sc.nextInt();
        }

        double sum = 0;
        for(int i=0 ; i<n ; i++){
            sum += (double)(p[i])/100 ; 
        }

        System.out.println((sum)/n*100);
        sc.close();
    }    
}
