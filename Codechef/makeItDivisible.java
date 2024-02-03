package Codechef;

import java.util.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	Scanner sc = new Scanner(System.in);
	int T = sc.nextInt();
	
	for(int i=1 ; i<=T ; i++){
	    int a = sc.nextInt();
	    
	    if(a == 1){
	        System.out.println(3);
	    }else{
	        System.out.print(1);
	        for(int j=1; j<=a-2; j++){
	            System.out.print(0);
	        }
	        System.out.print(5);
	        System.out.println();
	        
	    }
	  
	}
sc.close();

	}
}
