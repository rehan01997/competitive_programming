import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        String ques =sc.nextLine();
        
        ArrayList<String> ans = gss( ques);
        System.out.println(ans);
        
    }

    public static ArrayList < String > gss(String str) 
    {
        if( str.length() == 0)
        {
            ArrayList<String> base  = new ArrayList<>();
            base.add("");
            return base;
        }
        char ch = str.charAt(0);
        String rest = str.substring(1);
        
        
        ArrayList<String> ans = gss( rest );
        ArrayList<String> finalans = new ArrayList<>();
        for(String s : ans)
        {   
            finalans.add(s);
            finalans.add( ch + s);
        }
        return finalans;
    }

}