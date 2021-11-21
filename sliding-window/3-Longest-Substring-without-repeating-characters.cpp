class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0; 
        int right =0;
        unordered_map<char,int> m;
        int res=0;
        
        for(right=0; right <s.size(); right++){
            m[s[right]]++; 
            
            while(m[s[right]] > 1){      
                m[s[left]]--;
                left++;
            }
           
            res = max(res, right-left+1);
        }
        return res;
    }
};

