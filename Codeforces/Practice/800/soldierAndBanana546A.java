import java.util.*;

public class soldierAndBanana546A {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int w = sc.nextInt();
            int cost = 0;
            cost = (k*(w)*(w+1))/2; //Implementinig this for saving time
        // for(int i=1; i<=w; i++){
        //         cost += k*i;
        // }

        if(n-cost > 0)
        System.out.println(0);
        else
        System.out.println(cost-n);
        
        sc.close();
    }
}