import java.util.*;

public class Elephant617A{
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt(); 
        int steps = (x / 5) ;
        
        if(x % 5 == 0)
        steps+=0;
        else
        steps++;
        System.out.println(steps);
        sc.close();
    }
}