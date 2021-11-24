class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0, right =0, cnt=0, mx=0;
        while(right < nums.size()){
            if(nums[right] == 0) cnt++;
            while(cnt > k){
                mx = max(mx, right-left);
                if(nums[left] == 0) cnt--;
                left++;
            }
            right++;
        }
         mx = max(mx, right-left);
        return mx;
    }
};
