import java.util.*;

public class primeDeletion {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        int ind3 = 0, ind1 = 0;
        for(int i=1; i<=n ; i++){
            String seq = sc.next();
            for(int j=0 ; j<9; j++){
            if(seq.charAt(j) == '3')
            ind3 = j;
            if(seq.charAt(j) == '1')
            ind1 = j;
        }
        if(ind1 < ind3)
        System.out.println("13");
        else
        System.out.println("31");
        }

        

        
        sc.close();
    }
    
}
