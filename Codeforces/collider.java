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

            boolean[] isOn = new boolean[n+1];
            for(int i=1; i<=n ; i++){
            isOn[i] = false;
            }
            char sign1 = sc.next().charAt(0);
            int a1 = sc.nextInt();

            if(sign1 == '+'){
                isOn[a1] = true;
                System.out.println("Success");
            }else{
                System.out.println("Already off");
            }

            for(int i=0; i<m-1 ; i++){
                char sign = sc.next().charAt(0);
                int a = sc.nextInt();


            boolean check = true ; 
            for(int k=1; k<=n ; k++){
                check = isOn[k];

                if(check)
                break;
            }
            if(check){
            if(sign == '+'){

                if(isOn[a])
                System.out.println("Already on");

                for(int j=1; j<=n ; j++){
                    if(isOn[j]){
                        if(isRelaPrime(a, j) == false){
                            System.out.println("Conflict with "+j);
                        }else{
                            isOn[a] = true;
                            System.out.println("Success");
                        }
                    }
                }

            }if(sign == '-'){
                if(isOn[a] == false)
                System.out.println("Already off");
                else{
                    isOn[a] = false;
                System.out.println("Success");
            }
            }
        }else{
            isOn[a] = true;
                System.out.println("Success");
        }
            }
            
            sc.close(); 
            }
        }
        
        

    

