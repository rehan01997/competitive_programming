/*
Pattern
1	
1	1	
1	2	1	
1	3	3	1	
1	4	6	4	1
*/
import java.util.*;

public class Main
{
public static void main(String[] args)
{
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    
    /* nCr+1 = (n - r)* ncr/(r+1)
        we know nc0 = 1
    */    
    int ncr = 1;
    int new_ncr;
    for(int i = 0 ; i < n ; i++ )
    {
        for(int j = 0 ; j <= i ; j ++)
        {
            System.out.print(ncr + "\t");
            new_ncr = ( i - j)*ncr / (j + 1);  //i = n & j = r
            ncr = new_ncr;
        }System.out.println();
        ncr = 1;
    }    
}
}
