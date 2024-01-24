import java.util.*;

public class stonesOnTheTable {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String stones = sc.next();
        char[] sto = stones.toCharArray();
  
        int rmvStone = 0;

        for(int i=0 ; i<n-1; i++){
            if(sto[i] == sto[i+1]){
            rmvStone++;
            }
        }

        System.out.println(rmvStone);
    sc.close();  
    }
    
}
