import java.util.*;

public class helpfulMaths339A {
    public static void main(String[] args){
       Scanner sc = new Scanner(System.in);
       String sum = sc.nextLine();
int[] num = new int[(sum.length()/2)+1];
       for(int i=0,j=0 ; i<sum.length() ; i+=2, j++){
        num[j] = sum.charAt(i) - 48;
       }

     for(int i=0; i<sum.length()/2 ; i++){
        for(int j=i+1 ; i<sum.length()/2+1; j++){
            if(num[i] >= num[j]){
            int temp = num[i];
            num[i] = num[i+1];
            num[i+1] = temp;
            }
        }
     }

     for(int i=0 ; i<sum.length()/2+1; i++){
        System.out.println(num[i]);
     }
     sc.close();
    }
}
