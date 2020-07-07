#include<bits/stdc++.h>
using namespace std;
class compare
{
	public :
		bool operator()( const pair<int,pair<int,int>> p1 , const pair<int,pair<int,int>> p2)
		{
			return p1.first > p2.first;
		}
};
int main()
{
	int n; cin >> n;
	vector<vector<int>>arr(n);

	for(int i = 0 ; i < n ; i++)
	{
		int m; cin >> m;
		for(int j = 0 ; j < m ; j++)
		{	
			int no ; cin >> no;
			arr[i].push_back( no );
		} 
	}

	priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , compare >q;

	//priority_queue< pair<int,pair<int,int>> >q;

	for(int f = 0 ; f < arr.size() ; f++) { q.push({ arr[f][0] ,{ f , 0 }}); }  // ele , arr no , idx

	while( !q.empty())
	{
		pair<int,pair<int,int>> curr = q.top(); q.pop();
		cout << curr.first << " ";

		if(  (curr.second.second + 1 ) < arr[curr.second.first].size() )
		{
			q.push( { arr[curr.second.first][ curr.second.second + 1] , { curr.second.first , curr.second.second + 1 }} );
		}
	}
	return 0 ;
}