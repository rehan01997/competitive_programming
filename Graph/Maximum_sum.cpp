
#include <bits/stdc++.h> 
using namespace std; 

vector<vector<int>> depthFirst(int v, vector<int> graph[], vector<bool>& visited ) 
{  
	visited[v] = true; 
    vector<vector<int>>ans;

    bool hn = false; // to test whether its a leaf node or node
    for(auto i : graph[v] )
    {
        if(!visited[i] ) hn = true;
    }
    if( !hn )  // is leaf node return // base case
    { 
        ans.push_back({v}); 
        visited[v] = false;
        return ans;
    }
    for (auto i : graph[v])
    { 
        if (visited[i] == false)
         { 
			vector<vector<int>>recAns = depthFirst(i, graph, visited); 
            for(auto vec : recAns )
            {
                vec.push_back(v);
                ans.push_back(vec);
            } 
		 } 
	} 
    visited[v] = false;
    return ans;
} 
int maxSubarrSum(vector<int> arr , vector<int>& values)  //kadane algorithm
{
    int maxx = values[arr[0]-1];
    int tempsum = values[arr[0]-1];

    for(int i = 1 ; i < arr.size() ; i++ )
    {
        tempsum = max(tempsum + values[arr[i]-1] , values[arr[i]-1]);
        maxx = maxx > tempsum ? maxx : tempsum;
    }
    return maxx;
}
void maximumSumOfValues(vector<int> graph[], int vertices, vector<int> values) 
{ 
	// Initializing boolean array to mark visited vertices 
	vector<bool> visited(values.size() + 1, false); 

	// maxChain stores the maximum chain size 
	int maxValueSum = INT_MIN; 
    set<vector<int>>s;
	// Following loop invokes DFS algorithm 
	for (int i = 1; i <= vertices; i++) { 
		if (visited[i] == false) { 
			// int sum = 0; 

			// DFS algorithm 
			vector<vector<int>> ans = depthFirst(i, graph, visited); 
            
            for(auto vec : ans) s.insert(vec);

			// Conditional to update max value 
			// if (sum > maxValueSum) { 
			// 	maxValueSum = sum; 
			// } 
		} 
	} 
    for( auto it = s.begin() ; it != s.end() ; it ++)
    {
        for(auto ele : *it) cout << ele <<  " ";
        cout << endl;
    }
    for(auto it = s.begin() ; it != s.end() ; it++ )
    {
       int maxx = maxSubarrSum( *it , values);
       if( maxValueSum < maxx ) maxValueSum = maxx;
    }
    cout << endl;
	cout << "Max Sum value = "; 
	cout << maxValueSum << "\n"; 
} 
int main() 
{ 
	vector<int> graph[1001]; 
	int E = 4, V = 7; 
    int vtx ; cin >> vtx;

	vector<int> values; 
    for(int  i =0 ; i < vtx ;i++)
    {
        int no; cin >>no;
        values.push_back(no);
    }

	// Constructing the undirected graph 
    for(int i = 0 ; i < vtx - 1 ; i++)
    {
        int a , b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //cout << graph[0][0] ;
	maximumSumOfValues(graph, V, values); 
	return 0; 
} 
