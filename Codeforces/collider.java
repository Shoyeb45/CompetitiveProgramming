import java.util.Scanner;

public class collider {
    public static int isRelaPrime(int a, int b){
        int hcf = 0;
        for(int i=1; i<=a|| i<=b ; i++){
            if(a%i == 0 || b%i == 0){
                hcf = i;
            }
        }
        return hcf;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        System.out.println(isRelaPrime(n, m));
        sc.close();

    }
}
