import java.util.*;

public class almostLucky {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        if(n % 4 == 0 || n % 7 == 0) {
            System.out.println("YES");
        } else {
            boolean isLucky = false;
            int digit = 0;
            for(int i = n; i>=1; i=i/10){
                if(i % 10 == 4 || i % 10 == 7){
                    isLucky = true;
                }else{
                    isLucky = false;
                    break;
                }
            }
            
            for(int i = n; i>=1; i=i/10){
                digit++;
            }
          
            if(isLucky)
            System.out.println("YES");
            else {
                
                    if((digit == 2) && (n % 47 == 0 || n % 74 == 0)){
                        System.out.println("YES");
                    }else if ((digit == 3) && (n % 744 == 0 || n % 774 == 0 || n % 447 == 0 || n % 477 == 0 || n % 747 == 0 || n % 474 == 0 || n % 47 == 0 || n % 74 == 0)) {
                        System.out.println("YES");
                    }else{
                        System.out.println("NO");
                    }
                
            }
        }

        sc.close();
    }
}