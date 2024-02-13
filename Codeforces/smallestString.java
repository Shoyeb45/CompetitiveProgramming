import java.util.Scanner;

public class smallestString {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();

            if( n <= 28 ) {
                System.out.print("aa");
                System.out.println((char)(94+n));
            } else {
                if( n <= 52) {
                    System.out.print('a');
                    System.out.print((char)(96 + (n-27)));
                    System.out.println('z');
                } else {
                    if (n - 26 <= 26) {
                        System.out.print('a');
                        System.out.print((char)(96 + (n - 27)));
                    } else {
                        System.out.print((char)(96 + ((n - 26) - 26)));
                        System.out.print('z');
                    }
                    System.out.println("z");
                }
                }
            }
        }
    }

