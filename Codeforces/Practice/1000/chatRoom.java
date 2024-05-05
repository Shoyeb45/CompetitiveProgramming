import java.util.*;

public class chatRoom {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        int[] indices = new int[5];

        indices[2] = 1001;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'h' && indices[0] < i) {
                indices[0] = i;
            }
            else if (s.charAt(i) == 'e' && indices[1] < i) {
                indices[1] = i;
            } 
            else if (s.charAt(i) == 'l' && indices[2] < i && indices[3] < 0) {
                indices[3] = i;
            } 
            else if(s.charAt(i) == 'l' && indices[3] < i){
                indices[2] = i;
            } 
            else if (s.charAt(i) == 'o' && indices[4] < 0) {
                indices[4] = i;
            }
        }

        for(int i =0 ; i<5; i++){
            System.out.println(indices[i]);
        }
            if( (indices[1] > indices[0] && indices[1] < indices[2]) && (indices[2] > indices[1] && indices[2] < indices[3]) && (indices[3] > indices[2] && indices[3] < indices[4]) && (indices[4] > indices[3]) ) {
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }

        sc.close();
    }
}
