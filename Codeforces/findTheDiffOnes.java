import java.util.Scanner;

public class findTheDiffOnes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int i = 1; i <= t; i++){
            int n = sc.nextInt();

            int[] arr = new int[n];

            for(int j = 0; j <= n-1 ; j++){
                arr[j] = sc.nextInt();
            }
            int q = sc.nextInt();
            
            for(int j = 1; j <= q ; j++){
                int l = sc.nextInt();
                int r = sc.nextInt();
                
                for(int k = l-1 ; k<=r-1; k++){
                    for(int p = l ; p<=r-1; p++){
                        if(arr[k] != arr[p]){
                            System.out.println(k+" "+l);
                            break;
                        }
                    }
                }
            }

        }

    }
    
}
