import java.util.*;

public class DominoPiling50A {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int M = input.nextInt() ,N = input.nextInt();
int count = 0;
    if(M == 2 && N == 2){
         count = 2;
    }
    else if(M > 2 && N > 2){
        if(M % 2 == 0)
        count = (M / 2) * N;
        else{
           count = (M / 2) * N;
           if(N % 2 == 0)
           count += (N/2) ;  
        }
    }
    else if(M < 2 && N < 2){
    count = 0;
    }else if(M >= 2 && N < 2){
        count = (M/2) * N ;
    }else if(N >= 2 && M < 2){
        count = (N/2) * M ;
    }else if()
System.out.println(count);
        input.close();
    }
}