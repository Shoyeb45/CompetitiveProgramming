package Codechef;

import java.util.Scanner;

public class richieRich {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for(int p=1; p<=t ; p++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int x = sc.nextInt();
            int ans = 0; 
            int sum = a;
            for(int i=1; ; i++) {
                sum += x;
                if(sum >= b){
                    ans = i;
                    break;
                }
            }

            System.out.println(ans);
        }
        sc.close();
    }   
}
