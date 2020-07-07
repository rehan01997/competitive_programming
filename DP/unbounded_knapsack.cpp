#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n ; 
	cin >> n;

	vector<int>price(n);
	vector<int>wt(n);
	for(int i = 0 ; i < n ; i++)
	{	
		int a ; cin >> a;
		price[i] = a;
	}
	for(int i = 0 ; i < n ; i++)
	{
		int b; cin >> b;
		wt[i] = b;
	}
	int cap ;
	cin >> cap;

	vector<vector<int>>dp( n + 1 , vector<int>( cap + 1 , 0));

	for(int i = 1 ; i < dp.size() ; i++)
	{
		for(int j = 1 ; j < dp[0].size() ; j++)
		{
			//item taken
			if( ( j - wt[i - 1] ) >= 0 ) dp[i][j] = price[i - 1] + dp[i][j-wt[i - 1]];

			//not taken
			dp[i][j] = max( dp[i-1][j] , dp[i][j]); 
		}
	}
	// for(auto s : dp)
	// {
	// 	for(int no : s) cout << no << " ";
	// 	cout <<endl;
	// }
	cout << dp[n][cap];
	return 0 ;
}