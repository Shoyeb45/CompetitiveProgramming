import java.util.Scanner;

public class collider {
    public static boolean isRelaPrime(int a, int b){
        int hcf = 0;
        for(int i=1; i<=a|| i<=b ; i++){
            if(a%i == 0 && b%i == 0){
                hcf = i;
            }
        }
        if(hcf == 1)
        return true;
        else
        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[] reqNum = new int[m];
        boolean[] 
        for(int i=0; i<=m ; i++){
            char sign = sc.nextLine().charAt(1);
            int a = sc.nextInt();

            if(sign == '+'){
                if()
            }else{

            }
            
        }
        for(int i =0; i<m ; i++){
            System.out.println(reqNum[i]);
        }
        sc.close();

    }
}
