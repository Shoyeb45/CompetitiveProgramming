import java.util.Scanner;

public class perfectPermuatation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] perPerm = new int[n+1];

        for(int i = 1; i<=n ; i++){
            perPerm[i] = i;
        }

        for(int i=1; i<=n ; i++){
            for(int j=i+1; j<=n ;j++){
                int temp = perPerm[j];
                perPerm[j] = perPerm[i];
                perPerm[i] = temp;
                
                if(perPerm[perPerm[i]] == i && perPerm[i] != i)
                break;
                else{
                int temp2 = perPerm[i];
                perPerm[i] = perPerm[j];
                perPerm[j] = temp2;
            }
                
            
            }
        }
        if((n % 2) != 0)
        System.out.println(-1);
        else
        for(int i=1; i<=n ; i++){
            System.out.print(perPerm[i] + " ");
        }


        sc.close();
}
    
}
