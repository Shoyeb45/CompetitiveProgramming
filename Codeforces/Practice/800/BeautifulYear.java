import java.util.*;

public class BeautifulYear {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int y = sc.nextInt();
        int answer = 0;
        int[] number = new int[4];
        
        
        for(int i=y+1 ; ; i++){
            for(int j = 0, temp = i ; j<=3 ; j++, temp=temp/10){
                
            number[j] = temp % 10;
            
            }

            if( number[0] != number[1] && number[0] != number[2] && number[0] != number[3] && number[1] != number[2] && number[1] != number[3] && number[2] != number[3]  ) {
                answer = i;
                break;
        }
        }

        System.out.print(answer);
    sc.close();

 }
}
