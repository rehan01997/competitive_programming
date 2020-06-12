import java.io.*;
import java.util.*;

public class Main {

  public static class MinStack {
    Stack<Integer> data;
    int min;

    public MinStack() {
      data = new Stack<>();
    }

    int size() {
      // write your code here
      return data.size();
    }

    void push(int val) {
      // write your code here
      if( data.size() == 0)
      {
          min = val;
          data.push(val);
      }
      else if( val < min )
      {
          int pv = 2*val - min;
          data.push(pv);
          min = val;
      }
      else
      {
          data.push(val);
      }
    }

    int pop() {
      // write your code here
      if( data.size() == 0)
      {
          System.out.println("Stack underflow");
          return -1;
      }
      else
      {
          int pv = data.pop();
          if( pv < min)
          {
              int rv = min;
              min = 2*min - pv;
              pv = rv;
          }
          return pv;
      }
    }

    int top() {
      // write your code here
      if( data.size() == 0)
      {
          System.out.println("Stack underflow");
          return -1;
      }
      else
      {
          int tv = data.peek();#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = { {1,0} , {0,-1} , {0,1} , {-1,0} };

bool isvalid( int x , int y , vector<vector<char >>arr ,vector<vector<int >> ans , vector<vector<bool >>isvisited)
{   
    if( arr[x][y] == 'W') ans[x][y] = -1;
    if( x >= 0 && y >= 0 && x < isvisited.size() && y < isvisited[0].size() && !isvisited[x][y] && arr[x][y] != 'W' )
    {   
    
        return true;
    }
    return false;
}
int solve( vector<vector<char> >arr , vector<vector<bool >> visited , vector<vector<int>> ans , int r , int c)
{
    if( arr[r][c] == 'B')
    { 
        ans[r][c] = 0;
        return 0;
    }
    //int dist = 200;
    int dist = 200;
    
    if( ans[r][c] != 0 && ans[r][c] != -1) return ans[r][c];
    visited[r][c] = true;

    for(int d = 0 ; d < dir.size() ; d ++)
    {   
        int x = r + dir[d][0];
        int y = c + dir[d][1];
        
        if( isvalid(x , y , arr , ans , visited) )
        {
            int count = solve(arr , visited ,ans , x , y);
            if( count < dist) dist = count;
        }
    }
    ans[r][c] = dist + 1;
    visited[r][c] = false;
    return (dist + 1);
}

int main()
 {
int t ; 
cin >> t;
while( t--)
{
   int m;
   int n;
   cin >> n >> m;
   vector<vector<char> > arr( n , vector<char>(m,0));
   vector<vector<bool> > visited(n , vector<bool>(m,false));
   vector<vector<int> > ans( n , vector<int>(m,0));
   for(int i = 0 ; i < n ; i++)
   {
       for(int j = 0 ; j < m ; j++)
       {
           cin >> arr[i][j];
       }
   }
   
   for(int i = 0 ; i < n ; i++)
   {
       for(int j = 0 ; j < m ; j++)
       {
           if(ans[i][j] == 0)
           {
               solve(arr , visited ,ans , 0 , 0);
           }
        }
   }
   for(int i = 0 ; i < ans.size() ; i++)
   {
       for(int j = 0 ; j < ans[0].size() ; j++)
       {
           cout<<ans[i][j] << " ";
       }cout<<endl;
   }
}
return 0;
}


          if( tv < min)
          {
              tv = min;
          }
          return tv;
      }
    }

    int min() {
      // write your code here
      if( data.size() == 0)
      {
          System.out.println("Stack underflow");
          return -1;
      }
      else
      {
          return min;
      }
    }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    MinStack st = new MinStack();

    String str = br.readLine();
    while (str.equals("quit") == false) {
      if (str.startsWith("push")) {
        int val = Integer.parseInt(str.split(" ")[1]);
        st.push(val);
      } else if (str.startsWith("pop")) {
        int val = st.pop();
        if (val != -1) {
          System.out.println(val);
        }
      } else if (str.startsWith("top")) {
        int val = st.top();
        if (val != -1) {
          System.out.println(val);
        }
      } else if (str.startsWith("size")) {
        System.out.println(st.size());
      } else if (str.startsWith("min")) {
        int val = st.min();
        if (val != -1) {
          System.out.println(val);
        }
      }
      str = br.readLine();
    }
  }
}