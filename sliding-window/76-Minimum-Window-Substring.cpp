class Solution {
public:
    string minWindow(string s, string p) {
         unordered_map<char,int> needs;
          unordered_map<char,int> window;
        vector<int> res;
        
        int minLen = INT_MAX;
        
        for(char c1 : p) needs[c1]++;
        
        int left=0;
        int start;
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
                if( right - left +1 < minLen){
                    minLen = right - left +1;
                    start = left;
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
        
        return minLen == INT_MAX ? "" : s.substr(start,minLen);
    }
};




