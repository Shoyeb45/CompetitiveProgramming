import java.util.Arrays;
import java.util.Scanner;

public class JeffsAndPeriod {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<=n-1; i++) 
            arr[i] = sc.nextInt();

            if(n == 1) {
                System.out.println(1);
                System.out.println(arr[0] + " " + "0");
            } else {
                int[] indices = new int[n];
                int[][] pairs = new int[2][n];
                int ans = 0;

                for(int i=0; i<=n-1 ; i++) {
                    int count = 1;
                    indices[0] = i+1;

                    if(i+1 != n) {
                    for(int j=i+1; j<=n-1; j++ ) {
                        if(arr[i] == arr[j] && arr[i] > 0){
                            arr[j] = -9;
                            indices[count] = j+1;
                            count++;
                        }
                    }
                }
                    if(count == 1 && arr[i] > 0){
                        pairs[0][ans] = arr[i];
                        pairs[1][ans] = 0;
                        ans++;
                    } else {
                    int sum = 0;
                    for(int s=0; s<=count-1; s++) {
                        sum += indices[s];
                    }

                    int d = indices[1] - indices[0];
                    if(sum == ((count) * (indices[0] + indices[count-1])) / 2 && arr[i] > 0) {
                        pairs[0][ans] = arr[i];
                        pairs[1][ans] = d;
                        ans++;
                    }
                }
                }

                int[] finalAns = new int[ans];
                for(int i=0; i<=ans-1; i++) {
                    finalAns[i] = pairs[0][i];
                }
                Arrays.sort(finalAns);

                System.out.println(ans);
                for(int i=0; i<=ans-1; i++) {
                    
                    System.out.print(finalAns[i]);
                        for(int k=0; k<ans; k++) {
                            if(finalAns[i] == pairs[0][k]) 
                            System.out.println(" "+pairs[1][k]);

                        }
                }
            }
            
        sc.close();
    }
}
