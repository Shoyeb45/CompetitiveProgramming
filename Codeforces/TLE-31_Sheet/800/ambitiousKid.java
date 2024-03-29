import java.util.Scanner;

public class ambitiousKid {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        int smallestPos = Integer.MAX_VALUE;

        for(int i = 0; i < n; i++) {
            int temp = sc.nextInt();
            temp = Math.abs(temp);
            if(temp <= smallestPos) {
                smallestPos = temp;
            }
            
        }

        System.out.println(smallestPos);
        sc.close();
    }
}