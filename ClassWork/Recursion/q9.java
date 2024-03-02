package Recursion;

import java.util.Scanner;

public class q9 {
            public  static Boolean [] Alpha = new Boolean[26];  
    public static void Duplicates( String word , int ind ,String newWord){

        //Base case

    if( ind == word.length()){
        System.out.println(newWord);
        return;
    }

        char currChar = word.charAt(ind);
        if( Alpha[currChar -'a'] == true){
            Duplicates(word, ind+1, newWord);
        } else{
            newWord += currChar;
             Alpha[currChar - 'a'] = true;
             Duplicates(word, ind+1, newWord);
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String word = sc.next();

        for(int i =0 ; i<26 ;i++){
            Alpha[i]=false;
        }
        Duplicates(word , 0 ,"");
        sc.close();
    }
}
