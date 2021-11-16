class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int target = total / 2;
        
         if (total % 2 == 0) {
            return ((double) findKth(nums1, nums2, 0, 0, target) + findKth(nums1, nums2, 0, 0, target + 1)) / 2;
        } else {
            return (double) findKth(nums1, nums2, 0, 0, target + 1);
        }

    }
    
    int findKth(vector<int>& a, vector<int>& b, int startA, int startB, int k){
        if(startA >= a.size()){
            return b[startB + k-1];
        }
        if(startB >= b.size()){
            return a[startA +k -1];
        }
        if (k == 1) {
            return min(a[startA], b[startB]);
        }
        int midAIdx = startA +k/2 -1;
        int midBIdx = startB +k/2 -1;
        
        int midA = (midAIdx < a.size()) ? a[midAIdx] : INT_MAX;
        int midB = (midBIdx < b.size()) ? b[midBIdx] : INT_MAX;
        
        
        if (midA > midB) {
            return findKth(a, b, startA, startB + k / 2, k - k / 2);
        } else {
            return findKth(a, b, startA + k / 2, startB, k - k / 2);
        }
    }
};
