#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define INT_MAX 10000005
int32_t main() {
    int t; cin >> t;
    while(t--)
    {
    int n , k ;
    cin >> n >> k;
    int ans = INT_MAX;

    for(int i = 2 ; i*i <= k ; i++)
    {
        if(k%i == 0)
        {   
            int occ = 0;
            while(k%i == 0)
            {
                occ++;
                k = k/i;
            }

            int cnt = 0 ;
            //count no of multiples of i in n! 
            int p = i;

            while(p <= n)
            {
                cnt += n/p;
                p = p*i;
            }
            ans = min(ans , cnt/occ);
        }
    }
    if(k > 1)
    {
        int p = k;
        int cnt = 0 ;
        while( p <= n )
        {
           cnt += n/p;
           p *= k;
        }
        ans = min( ans , cnt );
    }    
    if( ans == INT_MAX) ans = 0;
    cout << ans << endl;
    }
    return 0;
}
