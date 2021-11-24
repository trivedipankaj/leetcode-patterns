class Solution {
public:
    unordered_map<int, vector<int>> G;
    unordered_map<int,bool> visited;
    queue<int> q;
    
    vector<int> res;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       buildGraph(root, NULL);
        
       q.push(target->val);
       visited[target->val] = true;
       
        int level =0;
        while(!q.empty()){
            int n  = q.size();
           
            while(n--){
               int curr = q.front(); q.pop(); 
               if(level == k){
                   res.push_back(curr);
               }
                for(int i=0; i<G[curr].size(); i++){
                    if(!visited[G[curr][i]]){
                        q.push(G[curr][i]);
                        visited[G[curr][i]] = true;
                    }
                }
              
            }
           level++;
        }
         return res;  
    }
    
    void buildGraph(TreeNode* root, TreeNode* parent){
        if(!root) return;
         
        if(parent){
            G[root->val].push_back(parent->val);
            G[parent->val].push_back(root->val);
        }
        buildGraph(root->left, root);
        buildGraph(root->right, root);
        
    }
};
