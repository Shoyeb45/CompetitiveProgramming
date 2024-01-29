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
        
        for(int i=0; i<m ; i++){
            String temp = sc.nextLine();
            
            // if(temp.charAt(0) == '+'){
            //     reqNum[i] = temp.charAt(2);
            // }else{
            //     reqNum[i] = -temp.charAt(2);
            // }
            
        }
        for(int i =0; i<m ; i++){
            System.out.println(reqNum[i]);
        }
        sc.close();

    }
}
