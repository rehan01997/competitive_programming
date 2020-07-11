*				*  
*				*  
*		*		*  
*	*		*	*	
*				*  
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	if( n == 1) { cout << "*    "; return 0;}
	int nsp1 = n - 2;

	int nsp2 = n/2 - 2;
	int nsp3 = 1 ;
	for(int i = 1 ; i <= n ; i++)
	{	    if( i <= n/2 )
			{   cout << "*	";
				for(int sp = 1 ; sp <= nsp1 ; sp++) cout << "	";
                cout << "*  " << endl;
                continue;
			}
			else if( i == n/2 + 1)
			{   cout << "*	";
				for(int sp = 1 ; sp <= n/2 - 1 ; sp++) cout << "	";
				cout << "*	";
				for(int sp = 1 ; sp <= n/2 - 1 ; sp++) cout << "	";
                cout << "*  "<< endl;
				continue;
			}
			else if( i > (n/2 + 1) && i < n)
			{   cout << "*	";
				for(int sp = 1 ; sp <= nsp2 ; sp++) cout << "	";
				cout << "*	";
				for(int sp = 1 ; sp <= nsp3 ; sp++) cout << "	";
				cout << "*	";
				for(int sp = 1 ; sp <= nsp2 ; sp++) cout << "	";
				cout <<"*	"; cout <<endl;
                nsp2 --;
			    nsp3 += 2;
			}
            else if( i == n)
            {   cout << "*	";
                for(int sp = 1 ; sp <= nsp1 ; sp++) cout << "	";
                cout << "*  " << endl;
            }		
	}
	return 0;
}
