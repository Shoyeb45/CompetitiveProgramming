import java.util.*;

public class VanyaAndFence {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int h = sc.nextInt();
        int[] heights = new int[n];

        for(int i = 0 ; i<=n-1; i++){
            heights[i] = sc.nextInt();
        }
        
        int minWidth = 0;
        
        for(int i = 0 ; i<=n-1; i++){
            if(heights[i] > h){
                minWidth += 2;
            }else{
                minWidth += 1;
            }
        }
        
        System.out.println(minWidth);

        sc.close();
    }
}