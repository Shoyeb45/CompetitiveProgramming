// package Codechef;

import java.util.Scanner;

public class vaccineDates {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int d = sc.nextInt();
            int l = sc.nextInt();
            int r = sc.nextInt();

            if(d <= r && d >= l)  System.out.println("Take second dose now");
            else if(d >= r) System.out.println("Too Late");
            else System.out.println("Too Early");
        }
        sc.close();
    }
    
}
