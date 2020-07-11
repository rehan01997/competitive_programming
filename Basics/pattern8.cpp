* * *  * * *
* *      * *
*          *
* *      * *
* * *  * * *
import java.util.*;

public class Main 
{
    public static void main(String[] args)
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        
        int nost = (n / 2) + 1;
        int nos = 1;
        
        for(int i = 1 ; i <= n ; i++ )
        {
            for(int st = 1 ; st <= nost ; st++ )
            {
                System.out.print("*	");
            }
            for(int sp = 1 ; sp <= nos ; sp ++)
            {
                System.out.print("	");
            }
            for(int st = 1 ; st <= nost ; st++ )
            {
                System.out.print("*	");
            }
            if( i <= n /2)
            {
                nos += 2;
                nost --;
            }
            else
            {
                nos += -2;
                nost ++;
            }
            System.out.println();
        }

    }
}
