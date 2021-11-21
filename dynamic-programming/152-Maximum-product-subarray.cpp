class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_ending = 1, min_ending=1, max_so_far = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
             int temp = max_ending;
            max_ending = max(nums[i], max(nums[i]*min_ending, nums[i]*max_ending));
            min_ending = min(nums[i], min(nums[i]*temp, nums[i]*min_ending));
            max_so_far = max(max_so_far, max_ending);
        }
       return max_so_far; 
    }
};
