class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int mn = candies[0];
        long long sum = mn;
        for(int i=1; i<candies.size(); i++){
            mn = max(mn, candies[i]);
            sum += candies[i];
        }
        
        if(sum < k){
            return 0;
        }
        int ans;
        
        int low = 1, high = mn;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(isFeasible(candies, mid, k)){
                ans = mid;
                low = mid+1;
            }else{
               high = mid-1;
            }
            
        }
        return ans;
    }
    
    bool isFeasible(vector<int>&candies, int pileSize, long long k){
        long long res =0;
        
        for(int i=0; i<candies.size(); i++){
            res += (candies[i] / pileSize);
        }
        return res >=k;
    }
};
