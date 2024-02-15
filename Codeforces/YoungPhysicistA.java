import java.util.*;

public class YoungPhysicistA {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        int[][] vectors = new int[n][3];

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<3 ; j++){
                vectors[i][j] = input.nextInt();
            }
        }

        int[] sum = new int[3];

        for(int i=0; i<n ; i++){
            sum[0] += vectors[i][0];
            sum[1] += vectors[i][1];
            sum[2] += vectors[i][2];
        }

        if(sum[0] == 0 && sum[1] == 0 && sum[2] == 0){
             System.out.println("YES");
        }else{
            System.out.println("NO");
        }

       
        
        input.close();
    }
    
}
