class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> window;
        unordered_map<char,int> needs;
        vector<int> res;
        
        for(char c1 : p) needs[c1]++;
        
        int left=0;
        int matches=0;
        
        for(int right=0; right<s.size(); right++){
            char c = s[right];
            
           if(needs.count(c)){
               window[c]++;
               if(window[c] == needs[c]){
                   matches++;
               }
           }
           
            while(matches == needs.size()){
                if(right -left +1 == p.size()){
                    res.push_back(left);
                }
                char c2 = s[left];
                if(needs.count(c2)){
                    window[c2]--;
                    if(window[c2] < needs[c2]){
                        matches--;
                    }
                } 
                
            left++;
            }
        }
        
        return res;
    }
};
