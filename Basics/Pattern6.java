/*
*	*	*	*			*
			*			*
			*			*
*	*	*	*	*	*	*	
*			*	
*			*	
*			*	*	*	*	

*/
import java.util.*;

public class Main 
{
    public static void main(String[] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ;j++)
            {
                if( i == n/2 + 1) System.out.print("*	");
                if( i > n/2 + 1 && j == 1 ) System.out.print("*	");
                if( i > n/2 + 1 && j > 1 &&  j < n/2 + 1) System.out.print("	");
                if( i != n/2 + 1 && j == n/2 + 1) System.out.print("*	");
                if( i == 1 && j <= n/2) System.out.print("*	");
                if( i!= 1 && i <= n/2 && j <= n/2) System.out.print("	");
                if( j == n && i <= n/2) System.out.print("*");
                if( i <=n/2 && j > n/2 + 1 && j < n ) System.out.print("	");
                if(i == n && j > n/2 + 1 ){  System.out.print("*	"); }//System.out.print("    "); }
               
                //if( i > n/2 + 1 && j > 1 &&  j < n/2 + 1) System.out.print("	");
                
            }System.out.println();
        }
        //System.out.print();
    }
}
