import java.util.*;

public class divisibilityProblem {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();

    int[][] response = new int[t][2];

    for(int i =0; i<t ; i++){
      for(int j=0; j<2 ; j++){
        response[i][j] = sc.nextInt();
      }
    }
int[] count = new int[t];
    for(int i=0 ; i<t ; i++){
      if(response[i][0] % response[i][1] != 0){
        count[i]++;
        response[i][0]++;
      }
    }

    for(int i=0 ;i<t ; i++){
      System.out.println(count[i]);
    }

  }
}
