class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        
        int d=0;
        int left =0;
        int mx =0;
        int maxf =0;
        for(int right=0; right< s.size(); right++){
            m[s[right]]++;
            maxf = max(maxf, m[s[right]]);
            
            while(right-left+1 - maxf > k){
                char c = s[left];
                m[c]--;
                left++;
            }
            mx = max(mx, right-left+1);
        }
        
        return mx;
    }
};
