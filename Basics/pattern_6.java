*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	
	*	*	*	*	*	*	*	*	*	*	*	*	*	*	
		*	*	*	*	*	*	*	*	*	*	*	*	*	
			*	*	*	*	*	*	*	*	*	*	*	*	
				*	*	*	*	*	*	*	*	*	*	*	
					*	*	*	*	*	*	*	*	*	*	
						*	*	*	*	*	*	*	*	*	
							*	*	*	*	*	*	*	*	
								*	*	*	*	*	*	*	
									*	*	*	*	*	*	
										*	*	*	*	*	
											*	*	*	*	
												*	*	*	
													*	*	
														*
                   import java.util.*;

public class Main 
{

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int nsp = 0;
        int nst = n;
        for(int  i = 1 ; i <= n ; i++ )
        {
            for(int  s = 1 ; s <= nsp ; s++ )
            {
                System.out.print("	");
            }
            for(int  t = 1 ; t <= nst ; t++ )
            {
                System.out.print("*	");
            }
            nsp++;
            nst --;
            System.out.println();
        }
    }
}
