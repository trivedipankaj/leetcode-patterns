class Solution {
public:
    deque<pair<int,int>> q;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            while(!q.empty() && q.back().first <= nums[i]) q.pop_back();
            q.push_back({nums[i],i});
            while(q.front().second <= i-k) q.pop_front();
            if(i+1>= k) res.push_back(q.front().first);
        }
        return res;
    }
};
