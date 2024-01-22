import java.util.*;

public class BeautifulMatrix263A {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int[][] matrix = new int[5][5];

        for(int i=0 ;i<5 ; i++){
            for(int j=0; j<5 ;j++){
                matrix[i][j] = input.nextInt();
            }
        }

        int count = 0 ;

        for(int i=0 ;i<5 ; i++){
            for(int j=0; j<5 ;j++){

                if(matrix[i][j] == 1){
                    if(i == 2 && j == 2){
                        count = 0 ;
                    }else if(i>2 && j>2){
                        for(int k=i ; k > 2 ;k--){
                            count++;
                        }
                        for(int k=j ; k > 2 ;k--){
                            count++;
                        }
                        // do {
                        //     count++;
                        //     --i;
                        // }while( i > 2);
                        // do {
                        //     count++;
                        //     --j;
                        // } while (j > 2);
                    }else if(i<2 && j<2){
                        do {
                            count++;
                            ++i;
                        } while (i != 2 );
                        do {
                            count++;
                            ++j;
                        } while (j != 2 );
                    }else if(i>2 && j<2){
                        for(int k=i ; k != 2 ;k--){
                            count++;
                        }

                        // do {
                        //     count++;
                        //     --i;
                        // } while (i > 2);
                        
                        do {
                            count++;
                            ++j;
                        } while (j != 2);
                    }else if(i == 2 ){
                        if(j < 2){
                        do {
                            count++;
                            ++j;
                        } while     (j != 2);
                        }else{
                            for(int k=j ; k != 2 ;k--){
                                count++;
                            }

                        // do {
                        //     count++;
                        //     --j;
                        // } while (j > 2 );

                        }
                    }else if(j == 2 ){
                        if(i < 2){
                        do {
                            count++;
                            ++i;
                        } while (i != 2);
                        }else{
                            for(int k=i ; k != 2 ;k--){
                                count++;
                            }

                        // do {
                        //     count++;
                        //     --i;
                        // } while (i > 2 );

                        }
                    }else{
                        do {
                            count++;
                            ++i;
                        } while (i != 2);
                        for(int k=j ; k != 2 ;k--){
                            count++;
                        }
                        // do {
                        //     count++;
                        //     --j;
                        // } while (j > 2);
                    }
                     
                   
                }
            }
        }

                System.out.print(count);
            input.close();
            }
        }
    
