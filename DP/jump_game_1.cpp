//Jump Game 55
https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        if( n == 0 ) return false;
        if( n == 1 ) return true;
        
        bool ans = 0;
        int reachable = 0;
        {
            for( int i = 0 ; i < n ; i++ )
            {
                if( reachable < i) return false;
                reachable = max( reachable , i + nums[i]);
            }
        }
        return true;        
    }
}; 
