import java.util.*;

public class BearAndBigBro {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int year = 0;
        for(int i=1; ;i++){
            a = a*3;
            b = b*2;
            if(a > b){
                year = i;
                break;
            }
        }
        System.out.println(year);
        sc.close();
    }
}
