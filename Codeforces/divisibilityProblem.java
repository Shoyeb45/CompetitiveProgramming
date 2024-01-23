import java.util.*;

public class divisibilityProblem {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();

int[] count = new int[t];

for (int i = 0; i < t; i++) {
  int a = sc.nextInt();
  int b = sc.nextInt();

  count[i] = (b - (a % b)) % b;
}


    for(int i=0 ;i<t ; i++){
      System.out.println(count[i]);
    }
sc.close();
  }
}
