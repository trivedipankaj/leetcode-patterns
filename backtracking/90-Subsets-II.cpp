class Solution {
public:
    vector<int> v1;
    vector<vector<int>> v;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
       subset(nums, 0);
        return v;
    }
    
    void subset(vector<int> nums, int pos){
        v.push_back(v1); 
        if(pos >= nums.size()){
             return; 
         }
        
        for(int i=pos; i<nums.size(); i++){
            if( i> pos && nums[i] == nums[i-1]) {continue;}
            v1.push_back(nums[i]);
            subset(nums, i+1);
            v1.pop_back();
        }
    }
};
