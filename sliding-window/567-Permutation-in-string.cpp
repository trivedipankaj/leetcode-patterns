class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        unordered_map<char,int> window;
        for(char s: s1) 
           window[s]++;
       
        int left=0;
        int matches=0;
        
        for(int right=0; right<s2.size(); right++){
             char c = s2[right];
             
             if(window.find(c) != window.end()){
                 window[c]--;
                 if(window[c] == 0)
                    matches++;
             }
             while(right -left +1 > k){
                 char ch= s2[left];
                 if(window.find(ch) != window.end()){
                     if(window[ch] == 0)
                        matches--;
                     window[ch]++;
                }
                 left++;
             }
            
              if( matches == window.size()){
                 return true;
             }
        }
        
        return false;
        
    }
};
