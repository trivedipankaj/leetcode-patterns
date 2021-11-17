class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string temp ="";
        generate(0,0, n, 0, temp);
        return res;
    }
    
   void generate(int open, int closed, int n, int index, string &s){
        if(open == n && closed ==n){
            res.push_back(s);
            return;
        }
        if(open < n){
                s.push_back('(');
                generate(open+1, closed, n , index+1, s);
                s.pop_back();
            }
            if(open > closed){
                s.push_back(')');
                generate(open, closed+1, n, index+1, s);
                s.pop_back();
            }
        
         }
};
