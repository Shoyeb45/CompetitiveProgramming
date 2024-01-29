import java.util.Scanner;

public class iLoveUsername {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] points = new int[n];
        for(int i = 0; i<n ; i++){
            points[i] = sc.nextInt();
        }
        int count = 0;

        for(int i = 1 ; i<n; i++){
            int max = points[0], min = points[0];
            for(int j = 0; j<i ; j++){
                if(points[j] > max)
                max = points[j];
                if(points[j] < min)
                min = points[j];
            }
            if(points[i] > max || points[i] < min)
                count++;
        }
        
        System.out.println(count);
        sc.close();
    }
}
