class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res =0;
        solve(root, res);
        return res;
    }
    
    int solve(TreeNode* root, int& res){
        if(root == NULL) return 0;
        
        int l = solve(root->left, res);
        int r = solve(root->right, res);
        
        int temp = 1 + max(l, r);
        res  = max(res, l+r);
        
        return temp;
    }
};
