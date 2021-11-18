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
    int result = INT_MIN;
    int maxPathSum(TreeNode* root) {
       maxSum(root, result);
        return result;
    }
    
    int maxSum(TreeNode* root, int &result){
        if(root ==NULL) return 0;
        int l = max(maxSum(root->left, result),0);
        int r = max(maxSum(root->right, result), 0);
        
        /**keep track of maximum value by adding root value, left and right sums*/
        int res = root->val + r +l;
        result = max(result, res);
        
        /*select only one path either via left or right**/
        return root->val + max(l,r);
    }
};
