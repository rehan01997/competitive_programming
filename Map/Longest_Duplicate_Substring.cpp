#include <bits/stdc++.h>
using namespace std;

vector<int>roll;     //1 , 26^1 , 26^2 , 26^3

long long hash_f( string &str , int i , int j , int prev_hash)
{
    int p = 0;
    long long h = 0;
    int size = j - i + 1;
    if( prev_hash == 0 )
    {
        for(int q = j ; q >= i ; q--)
        {
            // h += (( poww(26,p) * (str[q] - 'a')) % 100007) % 100007;
            h += (( roll[p] * (str[q] - 'a')) % 1000007) % 1000007;
            p++;
        }
    }
    else
    {
        //h = ( ((prev_hash - roll[size-1]*(str[i-1]-'a'))*26) % 100007 + (str[j] - 'a')) % 100007;  
        h = ( (((prev_hash - (roll[size-1]*(str[i-1]-'a'))%1000007 )%1000007)*26) % 1000007 + (str[j] - 'a')) % 1000007;  
    }
    return h;
}
void solve( string & str)
{	
    if( str.length() == 0 ) cout << "";
    int n = str.length();

    //roll fill    1, 26^1 , 26^2 , 26^3
    roll.resize(n);
    roll[0] = 1;
    for(long long i = 1 ; i < n ; i++)
    {
        roll[i] = (roll[i-1]*26 ) % 1000007;
    }
    //Binary search
    int l = 1;
    int r = n;
    string ans = "";

    while( l <= r)
    {        
        int mid = l + (r-l)/2;
        //cout << l <<" : " << r << " : " << mid << endl;
        map<long long,vector<int>>mp;      //hash_val , start pos.
        bool yes_ans = true;      //suppose we got answer                       
        long long h_func = 0;
        for(int i = 0 ; i <= n-mid ; i++)
        {
            h_func = hash_f( str , i , i+mid-1 , h_func );

            if( mp.find(h_func) != mp.end() )
            {   
                for(auto start : mp[h_func])
                {
                    int idx1 = start;
                    int idx2 = i;
                    string cmp1 = str.substr( idx1 , mid);
                    string cmp2 = str.substr( idx2 , mid);

                    if( cmp1.compare(cmp2) == 0)
                    {   yes_ans = false;
                        if( ans.size() < cmp1.size())
                        {                               
                            ans = cmp1;
                        }
                        l = mid + 1;
                    }
                    if(!yes_ans) break;                
                }
            }
            mp[h_func].push_back(i); 
        }
        if (yes_ans) r = mid - 1; 
    }
    cout << ans << endl;
}
int main() 
{   
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    string str; cin >> str;
    
    solve( str );
   // cout << hash_f( str , 0 , 4);
   // cout << poww(2,5);
    return 0;
}
