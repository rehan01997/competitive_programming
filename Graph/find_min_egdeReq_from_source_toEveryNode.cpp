#include<bits/stdc++.h>
using namespace std;

void dfs1(vector<vector<int>>graph , vector<bool>&vis , int src)
{
	vis[src] = true;

	for(int val : graph[src])
	{
		if(!vis[val]) dfs1(graph , vis , val);
	}
	return;
}
void dfs2(vector<vector<int>>&graph , vector<bool>&vis , vector<bool>&good , int u , int &cnt)
{
	good[u] = true;
	cnt++;
	for(int val : graph[u])
	{
		if(!vis[val] && !good[val])
		{
			dfs2( graph , vis , good , val ,  cnt);
		}
	}
	return;
}
int main()
{
	int t; cin >> t;
	while(t--)
	{	
		vector<vector<int>>graph;
		int n , m , src;
		cin >> n >> m >> src;
		graph.resize( n + 1);

		for(int i = 0 ; i < m ; i++)
		{
			int u , v;
			cin >> u >> v;
			graph[u].push_back(v);
		}

		vector<bool>vis( n + 1);
		map<int,vector<int>>val;

		
		dfs1( graph , vis , src );
		for(int i = 1; i <= n ;i++){ cout << vis[i] << " "; };
			cout <<endl;
		for(int i = 1 ; i <= n ; i++)
		{	
			vector<bool>good( n + 1);
			if(!vis[i])
			{
				int cnt = 0;
				dfs2( graph , vis , good , i , cnt);
				val[cnt].push_back(i);
			}
		}

		//sort(val.begin() , val.end() , greater<pair<int,int>>() );
		//reverse(val.begin() , val.end());

		int ans = 0;
		for(auto it = val.rbegin() ; it != val.rend() ; it++)
		{	//cout << it->first << " : ";
			for(auto val : it->second)
			{
				if(!vis[val])
				{
					ans++;
					dfs1(graph , vis , val);
				    cout << val << " ";	
				}		
			   //cout << val << " ";	
			}// << endl;
		}
		cout << ans << endl;
	}
return 0;
}

// 1
// 9 6 8
// 9 1
// 7 5
// 8 5
// 6 4
// 1 9
// 3 6
