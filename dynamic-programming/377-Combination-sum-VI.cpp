class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target+1,-1);
        
        return comb(nums, target, memo);
    }
    
    int comb(vector<int> &nums, int target, vector<int> &memo){
        if(target ==0 ) return 1;
        if(target < 0) return 0;
        if(memo[target] != -1) return memo[target];
        int cnt =0;
        
        for(int i=0; i<nums.size(); i++){
            cnt += comb(nums, target - nums[i], memo);
        }
        
        memo[target] = cnt;
        return cnt;
    }
};
