import java.util.Scanner;

public class theatreSquare {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a = sc.nextInt();

        if(n % a == 0 && m % a == 0){
            System.out.println((long)(((long)n*(long)m)/(long)((long)a*(long)a)));
        }else if(n % a != 0 && m % a == 0){
            System.out.println( (((long)n + ( a - ( n % a ) )) *m)/(long)((long)a*(long)a));
        }else if(n % a == 0 && m % a != 0){
            System.out.println( (((long)m + ( a - ( m % a ) )) *n)/(long)((long)a*(long)a));    
        }else{
            System.out.println( (((long)m + (a - (m % a)))*(n + (a - (n % a)))) / (long)((long)a*(long)a));
        }

        
        sc.close();
    }
    
}
