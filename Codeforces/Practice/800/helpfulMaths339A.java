import java.util.*;

public class helpfulMaths339A {
    public static void main(String[] args){
       Scanner sc = new Scanner(System.in);
       String sum = sc.nextLine();
int[] num = new int[(sum.length()/2)+1];
       for(int i=0,j=0 ; i<sum.length() ; i+=2, j++){
            num[j] = sum.charAt(i) - 48;
      }

     for(int i=0; i<num.length-1 ; i++){
        for(int j=i+1 ; j<num.length; j++){
            if(num[i] >= num[j]){
            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
            }
        }
     }

     for(int i=0 ; i<num.length ; i++){
        if(i == num.length - 1)
        System.out.print(num[i]);
        else
        System.out.print(num[i]+"+");
     }
     sc.close();
    }
}
