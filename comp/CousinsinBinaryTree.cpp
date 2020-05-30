/**
---https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
 * Definition for a binary tree node.
 
 
 
 
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<pair<TreeNode*,TreeNode* > >q;
        q.push(make_pair(root , root));
        
        bool f = false;
        while(!q.empty())
        {
            auto curr = q.front();
            int curr_size = q.size();
            TreeNode * parent ;
            for(int i = 0 ; i < curr_size ; i++)           // elements in the same level
            {
                TreeNode *child = curr.first;
                TreeNode *its_parent = curr.second; 
                
                if( child -> val == x || child -> val == y)
                {
                    if(f)   //if we got second ele in the same level
                    {
                        if( parent == its_parent) return false;     
                        else return true;
                    }
                    f = true;       //if we find only one ele in same level
                    parent = its_parent;
                }
                
                if(child -> left) q.push(make_pair( child->left , child));
                if( child -> right) q.push(make_pair( child-> right , child));
                
                q.pop();
                if( !q.empty() ) curr = q.front();
            }
            if(f) return false;    //if in kth level we find one element and cant find second element
        }
        
        return false;
    }
};
