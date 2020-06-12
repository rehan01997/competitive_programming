#include<bits/stdc++.h>
using namespace std;
struct QueueNode
{
    int i;
    int j;
    int dist;
    QueueNode(int r , int c , int distance)
    {
        i = r;
        j = c;
        dist = distance;
    }    
};
bool isvalid( int x , int y , int n , int m)
{   
    if ((x < 0 || x > n - 1) || (y < 0 || y > m - 1))
        return false;
    return true;
}
bool isSafe(int i, int j, vector<vector<char> >& matrix, vector<vector<int> >& result) 
{ 
    if (matrix[i][j] != 'O' || result[i][j] != -1) 
        return false; 
    return true; 
} 
vector<vector<int> > solve( vector<vector<char> >&arr , int n ,int m )
{  
    queue<QueueNode> q;   
    vector<vector<int> > ans( n , vector<int> ( m , -1) );  //every ele is -1
    vector<vector<int> > dir = { {1,0} , {0,-1} , {0,1} , {-1,0} };
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if( arr[i][j] == 'B' )
            {
                QueueNode t = { i , j , 0};
                q.push(t);
                ans[i][j] = 0;
            }
        }
    }
    while(!q.empty())
    {
        QueueNode temp = q.front();
        int a = temp.i;
        int b = temp.j;
        int dist = temp.dist;
       // cout<<q.size() << "   ";
        for(int d = 0 ; d < 4 ; d++)
        {
            int x = a + dir[d][0];
            int y = b + dir[d][1];

            if(isvalid( x , y , n , m) && isSafe(x , y , arr , ans))
            {
                ans[x][y] = dist + 1 ;
                QueueNode t = { x , y , dist + 1};
                q.push(t);
            }
        }
    q.pop();
    }    
    return ans;
}  
int main()
{
int t ; 
cin >> t;
while( t--)
{
   int n , m;
   cin >> n >> m;
   vector<vector<char> > arr( n , vector<char>(m,0));   
   for(int i = 0 ; i < n ; i++)
   {
       for(int j = 0 ; j < m ; j++)
       {
           cin >> arr[i][j];
       }
   }   
   vector<vector<int> > ans = solve(arr , n , m);
   for(int i = 0 ; i < n ; i++)
   {
       for(int j = 0 ; j < m ; j++)
       {
           cout<<ans[i][j] << " ";
       }cout<<endl;
   }
}
return 0;
}

// He has a blue print of the building which is a M x N matrix that is filled with the characters ‘O’, ‘B’, and ‘W’ where: 
// ‘O’ represents an open space.
// ‘B’ represents a bomb.
// ‘W’ represents a wall.
// You have to replace all of the O’s (open spaces) in the matrix with their shortest distance from a bomb without being able to go through any walls. Also, replace the bombs with 0 and walls with -1 in the resultant matrix. If no path exists between a bomb and an open space replace the corresponding 'O' with -1.
// Input:
// First line of input contains number of testcases T. For each testcase, first line contains space separated M and N respectively. Then M lines will follow containing N characters each.
// Output:
// Print the resultant integer matrix that denotes shortest distance of each open space cell from a bomb in the blue print of the building.
// Constraints: 
// 0 <= T <= 50
// 1 <= M,N <= 10
// Example:
// Sample Input:
// 1
// 3 3
// O O O
// W B B
// W O O
// Sample Output:
//  2 1 1 
// -1 0 0 
// -1 1 1 
