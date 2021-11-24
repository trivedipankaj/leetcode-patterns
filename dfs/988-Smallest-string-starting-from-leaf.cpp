/**
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
    string ans = "~";
    string smallestFromLeaf(TreeNode* root) {
      helper(root, "");
        
     return ans;
    }
    
    void helper(TreeNode* root, string s){
        if(!root) return;
        
        if(!root->left && !root->right){
            ans = min(ans, char(root->val +'a') +s);
            return;
        }
        
        helper(root->left, char(root->val +'a') +s);
        helper(root->right, char(root->val +'a') +s);
        
    }
};
