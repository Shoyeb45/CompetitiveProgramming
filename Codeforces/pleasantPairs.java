import java.util.*;

public class pleasantPairs {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        int[] answer = {0, 0, 0};

        for(int i=0 ; i<t ; i++){
            int n = sc.nextInt();

            int[] arr = new int[n];
            for(int j=0 ; j<n ; j++){
                  arr[j] = sc.nextInt();
            }

            for(int k=0 ; k<n ; k++){
                for(int j=k+1 ; j<n ; j++){
                    
                    if(k < j && arr[k]*arr[j] == k+j+2){
                     answer[i]+=1;
                    }
                }
                }
            }
        

    for(int i=0 ;i<3 ; i++){
        System.out.print(answer[i]+" ");
        }

        sc.close();
    }
}
