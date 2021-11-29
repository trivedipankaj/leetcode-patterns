class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
       unordered_map<int,vector<int>> g;
        unordered_map<int,int> in;
        
        vector<int> res;
        for(int i=0; i<num;i++){
            in[i] =0;
            g[i] = vector<int>();
        }
        
        for(int i=0; i<pre.size(); i++){
            int parent = pre[i][0];
            int child  = pre[i][1];
            
            g[parent].push_back(child);
            in[child]++;
        }
        
        queue<int> q;
        
        for(auto node: in){
            if(node.second ==0){
                q.push(node.first);
            }
        }
        
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            auto kids = g[curr];
            res.push_back(curr);
            
            for(int i=0; i<kids.size(); i++){
                in[kids[i]]--;
                if(in[kids[i]] == 0){
                    q.push(kids[i]);
                }
            }
        }
        
        if(res.size() != num){
            return vector<int>();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
