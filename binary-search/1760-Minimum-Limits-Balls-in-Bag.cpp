class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int h = 0;
        for(int num : nums){
            h = max(h, num);
        }
        
        int low = 1, high = h;
        while(low <high){
            int mid = low + (high - low)/2;
            
            if(isFeasible(nums, maxOperations, mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        
        return low;
    }
    
    bool isFeasible(vector<int>& nums, int maxOperations, int penalty){
        int count =0;
        for(int i=0; i<nums.size(); i++){
            count += (nums[i]-1)/penalty;
        }
        return count <=maxOperations;
    }
};
