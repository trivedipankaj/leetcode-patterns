class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
       int res=0;
        if(root == NULL) return 0;
        solve(root, root->val , res);
        return res;
    }
    
    int solve(TreeNode* root, int val, int& res){
        if(root == NULL) return 0;
        
        int left = solve(root->left, root->val, res);
        int right = solve(root->right, root->val, res);
         
        res = max(res, left+right);
        
        if(root->val == val) return max(left, right) +1;
        return 0;
        
    }
};
