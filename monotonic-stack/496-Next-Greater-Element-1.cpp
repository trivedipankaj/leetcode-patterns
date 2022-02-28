class Solution {
public:
    stack<int> s;
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         vector<int> ng;
          unordered_map<int,int> m;
    
        
        for(int i=0; i<nums2.size(); i++){
            while(!s.empty() && nums2[i] > s.top()){
                m[s.top()] = nums2[i];              
                s.pop();
            }
            s.push(nums2[i]);
        }
      
        for(int n: nums1){
            if(m.find(n) != m.end() ){
                ng.push_back(m[n]);
            }else{
                ng.push_back(-1);
            }
        }
    
        return ng;
    }
};
