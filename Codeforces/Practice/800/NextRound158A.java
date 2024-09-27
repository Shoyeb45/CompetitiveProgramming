import java.util.*;

public class NextRound158A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() , k = sc.nextInt();
        int[] scores = new int[n];

        for(int i=0 ;i<n ; i++){
            scores[i] = sc.nextInt();
        }
        int advancers = 0;
for(int i=0 ;i<n ; i++){
    if(scores[i] > 0){
    if(scores[i] >= scores[k-1]){
    ++advancers;
}
    }
}
        System.out.println(advancers);

        sc.close();
    }
    
}
