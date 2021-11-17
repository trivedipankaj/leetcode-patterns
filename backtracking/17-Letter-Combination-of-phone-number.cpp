class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return vector<string>();
        vector<string> options = {"","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        string temp="";
        backtrack(digits, options, temp, 0,res);
        return res;
        
    }
    
    
    void backtrack(string &digits, const vector<string> &options, string &sb,  int index , vector<string> &res ){
        if(index >= digits.size()){
            res.push_back(sb);
            return;
        }
        
        string curr = options[digits[index]-'0'];
       
        for(char c : curr){
            sb.push_back(c);
            backtrack(digits, options, sb, index+1,res);
            sb.pop_back();
        }
    }
    
};
