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
//***********connectd components in graph******

vector<vector<int >> comps;

void traverse( vector<int > & scomp , int src ,vector<bool>&visited)
{
	visited[src] = true;
	scomp.push_back( src );
	for(int i = 0 ; i < graph[src].size() ; i++)
	{	
		Edge * curr = graph[src][i];
		if( !visited[ curr -> v ] )
		{
			traverse( scomp , curr -> v ,visited);
		}
	}
	return;
}
void connected_edge()
{
	vector<bool> visited( graph.size(), false);
	for(int src = 0 ; src < graph.size() ; src++)
	{
		if( !visited[src] )
		{
			vector<int> scomp ;
			traverse( scomp , src ,visited );
			comps.push_back( scomp );
		}
	}
	return;
}
//*********isGraph connected*****
// vector<bool>visited( graph.size() , false);
void isGraphConnected( vector<bool> &visited ,int src )
{
    visited[src] = true;
    for(int i = 0 ; i < graph[src].size() ; i++)
    {   Edge * curr = graph[src][i];
        if(!visited[curr -> v])
        {
            isGraphConnected( visited , curr -> v );
        }
    }
    return;
}
//*********************Hamiltanion_cycle and path**
void hPAC(int src , vector<bool>&visited , vector<int>&path)
{
	if( path.size() == (graph.size() - 1))  // base case
	{
		path.push_back( src );    //add last element
		for(int i = 0 ; i < path.size() ; i++)      //print path`
		{
			cout << path[i];
		}
		bool isCycle = false;
		int first_ele = path[0];                    //user given source
		for(int e = 0 ; e < graph[src].size() ; e++)   //to comapre whether last ele is connectd to user given src
		{
			Edge * currE = graph[src][e];
			if( currE -> v == first_ele)           //is yes ,its a cycle
			{
				isCycle = true;
				break;
			}
		}
		if( isCycle ) cout << "*";
		else cout << ".";
		cout << endl;
		path.pop_back();                          //backtracking
		return;
	}
	visited[ src ] = true;
	path.push_back( src );
	for(int i = 0 ; i < graph[src].size() ; i++)
	{
		Edge *curr = graph[src][i];
		if( !visited[ curr -> v])
		{
			hPAC( curr -> v , visited , path);
		}
	}
	path.pop_back();							//backtracking
	visited[src] = false;						//backtracking
	return;
}
void bfs( int src)
{
	queue<pair<int,string>> q;
	vector<bool>visited( graph.size() , false);
	q.push( { src , to_string( src ) });
	
	while( !q.empty())
	{
		pair<int , string > curr = q.front();  
		q.pop();

		if(!visited[curr.first])
		{
			cout << curr.first <<"@" << curr.second << endl;	
		}
		//else continue;
		visited[ curr.first ] = true;
		
		for(int e = 0 ; e < graph[ curr.first ].size() ; e++)
		{
			Edge * cP = graph[curr.first][e];
			if( !visited[ cP -> v] )
			{
				q.push( { cP -> v , curr.second + to_string( cP -> v)});
			}
		}	
	}
}
//************shortestPathinWeights*******
class bfds
{
	public:
		int src;
		int weightSofar;
		string path;

		bfds(int src , int weightSofar , string path)
		{
			this -> src = src;
			this -> weightSofar = weightSofar;
			this -> path = path;
		}
};
class compare
{
	public:
		bool operator()(const bfds * p1 ,const bfds * p2 )
		{
			return p1 -> weightSofar > p2 -> weightSofar; 
		}
};
void shortestPathInWeights(int src)
{
	priority_queue<bfds* , vector<bfds*> , compare> q;
	vector<bool>visited( graph.size() , false);
	q.push( new bfds(src , 0 , to_string(src) ));

	while( !q.empty())
	{
		bfds * curr = q.top();  q.pop();
		
		if(!visited[ curr -> src ])
		{
			cout << curr -> src <<" via " << curr->path << " @ " << curr->weightSofar << endl;	
		}
		visited[ curr -> src] = true;

		for(int e = 0 ; e < graph[curr -> src].size() ; e++)
		{
			Edge* cuurP = graph[curr->src][e];
			if( !visited[ cuurP -> v] )
			{
				q.push(new bfds( cuurP->v , curr->weightSofar + cuurP -> wt , curr->path + to_string( cuurP->v ) )); 
			}
		}
	} 
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
	
	//display();

	// int s,d;
	// cin >> s >> d;
	// vector<bool> isVisited( no_vertex , false );
	// bool ans = hasPath( s , d , isVisited );
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


	// connected_edge();
	// for(int i = 0 ; i < comps.size() ; i++)
	// {
	// 	for(int j = 0 ; j < comps[i].size() ; j++)
	// 	{
	// 		cout << comps[i][j] << " ";
	// 	}cout<<endl;
	// }
    
    // vector<bool>visited(graph.size() , false);
    // isGraphConnected( visited , 0);
    // bool ans = true;
    // for(int i = 0 ; i < visited.size() ; i++)
    // {
    //     if( !visited[i] ) 
    //     {
    //         ans = false;
    //         break;
    //     }
    // }
    // if( ans ) cout <<"true";
    // else cout <<"false";

	//****hamiltom
	// int src;
	// cin >> src;
	// vector<bool>visited( graph.size() , false);
	// vector<int>path;
	// hPAC( src , visited , path);


	// int src;
	// cin >> src;
	// bfs(src);

	int src;
	cin >> src;
	shortestPathInWeights( src );
	return 0;
}	
