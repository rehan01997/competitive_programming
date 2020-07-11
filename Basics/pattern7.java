    *
   * *
  * * *
   * *
    *

import java.util.*;

public class Main 
{
    public static void main(String[] args) 
    {
        Scanner scn = new Scanner(System.in);
    
        int n = scn.nextInt();
        
        int nos = ( n / 2) + 1;
        int nost = 1 ;
        for ( int i = 1 ; i <= n ; i++)
        {
            for(int sp = 1 ; sp < nos ; sp++ )
            {
                System.out.print("	");
            }
            for(int st = 1 ; st <= nost ; st++)
            {
                System.out.print("*	");
            }
            for(int sp = 1 ; sp < nos ; sp++ )
            {
                System.out.print("	");
            }
            System.out.println();
            if( i <= n/2)
            {
                nos -- ;
                nost += 2;
            }
            else
            {
                nos ++;
                nost -= 2;
            }
        }
    }
}
