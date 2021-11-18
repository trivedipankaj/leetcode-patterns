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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        pathSumUtil(root, v , 0, targetSum);
        return res;
    }
    
    void pathSumUtil(TreeNode* root, vector<int> path, int sum, int targetSum){
       if(!root){
           return;
       }
       path.push_back(root->val);
        
       if(root->left == NULL && root->right == NULL){
           if(sum + root->val == targetSum){
               res.push_back(path);
           }
       }
       
       pathSumUtil(root->left, path, sum+root->val, targetSum);
       pathSumUtil(root->right, path, sum+root->val, targetSum);
    
       path.pop_back();
    }
};
