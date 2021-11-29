class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> g;
        unordered_map<int,int> in;
        
        vector<int> res;
        /*
        Initiate the graph and inorder vector
        */
        for(int i=0; i<num;i++){
            in[i] =0;
            g[i] = vector<int>();
        }
        
        /**
        Maintain the inorder degree
        Build the graph - adjancey list
        ***/
        
        for(int i=0; i<pre.size(); i++){
            int parent = pre[i][0];
            int child  = pre[i][1];
            
            g[parent].emplace_back(child);
            in[child]++;
        }
        
        queue<int> q;
        
        /*
        start with the nodes with 0 inorder degree
        do a BFS
        */
        for(auto node: in){
            if(node.second ==0){
                q.push(node.first);
            }
        }
        
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            auto kids = g[curr];
            res.emplace_back(curr);  //push the node with zero indegree
            
            for(int i=0; i<kids.size(); i++){
                in[kids[i]]--;   //remove the edge
                if(in[kids[i]] == 0){
                    q.push(kids[i]);
                }
            }
        }
        
        return res.size() == num;
    }
};
