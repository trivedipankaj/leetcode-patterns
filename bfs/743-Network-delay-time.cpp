typedef pair<int,int> pii;

class Solution {
public:
    unordered_map<int, vector<pii>> g;
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(const auto& t: times){
            g[t[0]].push_back({t[1],t[2]});
        }
        const int inf = 1e9;
        vector<int> dist(n+1, inf);
        dist[k] = 0;
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,k});
        
        int u, v, w;
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            u = curr.second;
            for(auto& to: g[u]){
                v = to.first, w = to.second; 
                if(dist[v] > dist[u] +w){
                    dist[v] = dist[u]+w;
                    pq.push({dist[v],v});
                }
                
            }
            
        }
        
        int ans=-1;
        for(int i=1; i<dist.size(); i++){
            ans = max(ans,dist[i]);
        }
        return ans == inf ? -1 : ans;
    }
};

