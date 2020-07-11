			*	
		*		*	
	*				*	
*						*	
	*				*	
		*		*	
			*	
n = 7(odd)

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n ; cin >> n;

	int nsp1 = n/2 - 1;
	int nsp2 = 1;
	int nst = 2;

	for(int i = 1 ; i <= n ; i++)
	{	
		if( i == 1 || i == n )
		{
			for(int j = 1 ; j <= n / 2; j++ ) cout << "	";
			cout << "*	";
            //nsp1++;
            cout << endl;
            continue;
		} 
		else
		{	
			int count = 1; 
			for(int j = 1 ; j <= nsp1 ; j++ ) cout << "	";
			if( count <= nst) { cout << "*	" ; count++; }
			for(int j = 1 ; j <= nsp2 ; j++ ) cout << "	";
			if( count <= nst ) cout << "*	";
            cout << endl;
		}
		if( i < n/2 + 1) { nsp1-- ; nsp2 = nsp2 + 2 ;}
		else if( i >= n/2 + 1) { nsp1 ++ ; nsp2 = nsp2 - 2; }   
	}
}
