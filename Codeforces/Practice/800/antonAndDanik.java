import java.util.*;

public class antonAndDanik{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String res = sc.next();
        int winA = 0, winD = 0;

        for(int i=0; i<n ; i++){
            if(res.charAt(i) == 'A')
            winA++;
            else
            winD++;
        }
        if(winA > winD)
    System.out.print("Anton");
    else if(winA == winD)
    System.out.print("Friendship");
    else
    System.out.print("Danik");

    sc.close();
    }
}