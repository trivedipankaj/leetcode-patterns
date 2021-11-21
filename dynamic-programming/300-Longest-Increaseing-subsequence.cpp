class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
  
        int n = nums.size(), res = 0, max_len = 0;
        vector<int> dp(n+1, 1);
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j <i ; j++){
                if(nums[i] > nums[j]){
                   dp[i] = max(dp[j]+1, dp[i]);
                }
            }
            max_len = max(max_len, dp[i]);
  }
        return max_len;
    }
};
