import java.util.*;

public class arrivalOfTheGeneral {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] line = new int[n];
        for(int i = 0; i<n; i++){
            line[i] = sc.nextInt();
        }

        int max = line[0], min = line[0];
        for(int i=0 ; i<n ; i++){
            if(line[i] >= max)
            max = line[i];
        }
        for(int i=n-1 ; i>0 ; i--){
            if(line[i] <= min)
            min = line[i];
        }
        
        int pMin = 0, pMax = 0;
        for(int i=0, j=n-1 ; i<n ; i++, j--){
            if(line[i] == min)
            pMin = i;
            if(line[j] == max)
            pMax = j;
        }
    
        if(pMin < pMax ){
            System.out.println((pMax-0)+(n-1-pMin)-1);
        }else{
            System.out.println((pMax-0)+(n-1-pMin));
        }
    }
}
