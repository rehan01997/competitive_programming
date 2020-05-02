import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        printEncodings(str , "");
        System.out.println();
    }
    public static void printEncodings(String str , String ans) 
    {
        if( str.length() == 0)
        {
            System.out.println(ans);
            return;
        }
        
        int num0 = (int)(str.charAt(0) - '0');
        if(num0 == 0 ) return;
        
        char code0 = (char)( str.charAt(0) +'a' - '1');
        printEncodings( str.substring(1) , ans + code0);
        
        if( str.length() > 1)
        {
            int num1 = (int)(str.charAt(1) - '0');
            int num = num0 * 10 + num1;
            
            if( num <= 26)
            {
                char code1 = (char)( num - 1 + 'a');
                printEncodings(str.substring( 2) , ans + code1);
            }
        }
        return ;
    }

}