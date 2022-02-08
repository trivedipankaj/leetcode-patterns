class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     if(nums.size() == 0){
         return vector<int>{-1,-1};
     } 
     vector<int> res;
     res.push_back(getLeftSide(nums, target)); 
      res.push_back(getRightSide(nums, target));  
     return res;
    }
    
    
    int getLeftSide(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size()-1;
        
        while(low < high){
         int mid = low + (high - low)/2;
         if( target <= nums[mid] ){
             high = mid;
         }else{
             low = mid+1;
         } 
        }
        return nums[low] == target ? low : -1;   
    }
    
    int getRightSide(vector<int>& nums, int target){
         int low = 0;
         int high = nums.size()-1;
     
          while(low < high){
             int mid = low + (high - low+1)/2;
             if( target >= nums[mid] ){
                 low =mid;
             }else{
                 high = mid-1;
             }
         }
       return nums[low] == target ? low : -1;     
    }
    
    
};
