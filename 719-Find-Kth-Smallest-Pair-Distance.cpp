class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];
        
        while(low < high){
            int mid = low + (high-low)/2;
           
            if(isFeasible(nums, k, mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        
        return low;
    }
    
    
    bool isFeasible(vector<int>& nums, int k, int distance){
        int j=0;
        int count =0;
         int n = nums.size();
        
        for(int i=0; i<nums.size(); i++){
            while(j<n && nums[j]- nums[i] <=distance) j++;
            count += j-i-1;
        }
        
        return count >=k;
    }
};
