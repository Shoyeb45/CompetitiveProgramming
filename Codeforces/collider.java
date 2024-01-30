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

            boolean[] isOn = new boolean[m+1];
            for(int i=1; i<=m ; i++){
            isOn[i] = false;
            }

            for(int i=1; i<m+1 ; i++){
            char sign = sc.next().charAt(0);
            int a = sc.nextInt();
            
            }
            
            sc.close(); 
            }
        }
        
        

    

