class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low =0; 
        int high = removable.size();
        while(low  < high){
            int mid = low + (high - low)/2;
            if(isFeasible(s, p,removable, mid )){
               low = mid+1;
            }else{
               high = mid;
            }
        }
        return low;
    }
    
    bool isFeasible(string s, string p, vector<int>& removable, int k){
        int n = s.size();
        int m = p.size();
        vector<bool> f(n, false);
        for(int q=0; q<=k; q++){
            f[removable[q]] = true;
        }
        int i =0,j=0;
        int l=0;
        while(i < n && j < m ){
            if(f[i]){
                i++;
                continue;
            }
            if(s[i]  == p[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j == m;
    }
};
