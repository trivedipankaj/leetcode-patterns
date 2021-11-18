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
    int res =0;
    int pathSum(TreeNode* root, int targetSum) {
        queue<TreeNode*> q;
        if(root == NULL) return 0;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto curr = q.front(); q.pop();
                 getSumCount(curr, 0, targetSum);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return res;
    }
    
    void getSumCount(TreeNode* root, int sum, int target){
        if(root == NULL) return ;
        if(sum + root->val == target){
            res++;
        }
        getSumCount(root->left, sum + root->val , target); 
        getSumCount(root->right, sum + root->val, target);
        
    }
};
