class Solution {
public:
    vector<int> findMinHeightTrees(int num, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> g;
        unordered_map<int,int> in;
        if(num == 1){
            return vector<int>(1,0);
        }
        vector<int> res;
        for(int i=0; i<num;i++){
            in[i] =0;
            g[i] = vector<int>();
        }
        
        for(int i=0; i<pre.size(); i++){
            int parent = pre[i][0];
            int child  = pre[i][1];
            
            g[parent].push_back(child);
            g[child].push_back(parent);
            in[child]++;
            in[parent]++;
        }
        
        queue<int> q;
        
        for(auto node: in){
            if(node.second ==1){
                q.push(node.first);
            }
        }
        
        while(!q.empty()){
            int n = q.size();
            res.clear();
    
            while(n--){
                auto curr = q.front(); q.pop();
                auto kids = g[curr];
                res.push_back(curr);

                for(int i=0; i<kids.size(); i++){
                    in[kids[i]]--;
                    if(in[kids[i]] == 1){
                        q.push(kids[i]);
                    }
                }
            }
        }
        
        return res;
    }
};
