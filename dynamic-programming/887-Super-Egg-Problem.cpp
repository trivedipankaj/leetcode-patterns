class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> res(k+1, vector<int>(n+1,-1));
        return solve(k, n, res);
    }
    
    int solve(int k, int n, vector<vector<int>> &res){
      
        if(n ==0 || n==1) return n;
        if(k ==1 ) return n;
      
         if(res[k][n] != -1) return res[k][n];
        
        int mn = INT_MAX;
    
        int lo = 1, hi = n;
        while(lo <= hi){
            int mid = lo + (hi -lo)/2;
            int broken = solve(k-1, mid-1, res); 
            int not_broken = solve(k, n- mid, res); 
           
            if(broken > not_broken){
                hi = mid - 1;
                mn = min(mn, broken + 1);
            }else{
                lo = mid + 1;
                mn = min(mn, not_broken + 1);
            }
        }
        
        return res[k][n] = mn;
    }
};
