// package Codechef;

import java.util.Scanner;

public class ceaserCipherLite {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            String text = sc.next();
            String encryText = sc.next();
            int[] ans = new int[n];
            
            for(int i=0; i<n; i++) {
                
                if(text.charAt(i) == encryText.charAt(i)) {
                    ans[i] = 0;
                } else {
                    int cnt = 0;
                    int j = (int) text.charAt(i) + 3;
                    for(; ; j+=3) {
                            cnt++;
                        if((int)(encryText.charAt(i)) == (j)) {
                            ans[i] = cnt;
                            break;
                        }

                        if(j == 90)  j = 64;
                        else if(j == 89)  j = 63;
                        else if(j == 88)  j = 62;
                    }
                }

            }
            for(int i=0; i<=n-1; i++)   System.out.print(ans[i] + " ");
            System.out.println();
        }
        sc.close();   
    }
}
