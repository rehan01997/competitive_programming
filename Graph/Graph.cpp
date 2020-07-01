#include<bits/stdc++.h>
using namespace std;

class Edge
{
	public:
		int v;   //dest
		int wt;  //weight

		Edge( int v , int wt)
		{
			this -> v = v;
			this -> wt = wt;
		}
};
vector<vector<Edge*> >graph;
void addEdge( int u , int v , int wt)
{
	if( u < 0 || v < 0 || u >= graph.size() || v >= graph.size() ) return;

	graph[u].push_back( new Edge( v , wt ));
	graph[v].push_back( new Edge (u , wt ));
	return;
}

void display()
{
	for(int i = 0 ; i < graph.size() ; i++)
	{
		cout << i << "-->>";
		for(int j = 0 ; j < graph[i].size() ; j++)
		{
			cout << "(" << graph[i][j] -> v << "," << graph[i][j] -> wt <<")" << "  ";
		} 
		cout <<endl;
	}
	return;
}
bool hasPath( int src , int dest , vector<bool>isVisited)
{
	if( src == dest) return true;

	isVisited[src] = true;

	for(int i = 0 ; i < graph[src].size() ; i++)
	{
		Edge * curr = graph[src][i];
		if( !isVisited[ curr -> v ] )
		{
			bool recAns = hasPath( curr -> v , dest ,isVisited);
			if( recAns ) return true;	
		}			
	}
	return false;
}
vector<string> printAllPaths( int src , int dest , vector<bool>isVisited)
{
	if(src == dest)
	{
		vector<string>base;
		base.push_back( to_string(src) + "" );
		return base;
	}
	isVisited[src] = true;
	vector<string>ans;

	for(int i = 0 ; i < graph[src].size() ; i++)
	{
		Edge * curr = graph[src][i];
		if( !isVisited[ curr -> v ])
		{
			vector<string> recAns = printAllPaths( curr -> v , dest , isVisited);
			for( string s : recAns)
			{
				ans.push_back( to_string(src) + s );
			}			
		}
	}
	isVisited[src] = false;
	return ans;
}
int main()
{
	int no_vertex;
	int n;

	cin >> no_vertex;
	cin >> n;	

	graph.resize(no_vertex);   //resize
	for(int i = 0 ; i < n ; i++ )
	{
		int src;
		int dest;
		int wt;

		cin >> src >> dest >> wt;
		addEdge( src , dest , wt);
	}
	
	display();

	// int s,d;
	// cin >> s >> d;
	// vector<bool> isVisited( no_vertex ,false);
	// bool ans = hasPath( s ,d, isVisited);
	// if( ans ) cout << "true";
	// else cout << "false";

	// int s,d;
	// cin >> s >> d;
	// vector<bool>isVisited(no_vertex , false);
	// vector<string> ans = printAllPaths( s , d , isVisited);
	// for( string s : ans)
	// {
	// 	cout << s << endl;
	// }


	return 0;
}	