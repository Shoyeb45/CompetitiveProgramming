import java.util.*;

public class oddDivisor {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int i=0; i<t ; i++){
            long a = sc.nextLong();

            if((a & 1) == 1){
                System.out.println("Yes");
            }else{
                boolean ans = false;
                long temp = a;

                while (temp > 2) {
                    temp /= 2;

                    if((temp & 1) == 1){
                        ans = true;
                        break;
                    }   
                }

                if(ans)
                System.out.println("YES");
                else
                System.out.println("NO");
            }
        }
        sc.close();
    }
}