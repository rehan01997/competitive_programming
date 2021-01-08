// https://leetcode.com/problems/jump-game-ii/
// LC - 45

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        // O( N2 ) 
//         vector<int>dp ( n , 0);
        
//         for( int i = n-1 ; i >= 0 ; i-- )
//         {
//             int minn = INT_MAX;
//             for( int j = 1 ; j <= nums[i] && i+j <= n-1 ; j++ ) 
//             {
//                 if( i + j == n-1 ) minn = min( minn , dp[i+j] ); 
//                 else if( dp[i+j] != 0 ) minn = min( minn , dp[i+j] );
                
//                 if( minn == INT_MAX ) dp[i] = 0;
//                 else dp[i] = minn + 1;
//             }
//         }
//         for( int ele : dp ) cout << ele << " ";
//         return dp[0];
        // O( N )
        int curr_reach = 0;
        int steps = 0;
        int curr_maxx = 0;
        
        for( int i = 0 ; i < n-1 ; i++ )
        {
            if( i + nums[i] > curr_maxx) curr_maxx = i + nums[i];
            if( i == curr_reach )
            {
                steps ++;
                curr_reach = curr_maxx;
            }
        }
        return steps;
    }
};
