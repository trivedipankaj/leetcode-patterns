class Solution {
public:
    int minInsertions(string s) {
        int m = s.size();
        
        vector<vector<int>> mem(m,vector<int>(m));
        int n = lps(s, 0, m-1, mem );
        
        return m-n;
    }
    
    int lps(string &s, int i, int j , vector<vector<int>> &mem){
        if( i == j) return 1;
        if( i > j ) return 0;
        if(mem[i][j]) return mem[i][j];
        if(s[i] == s[j]) { 
            mem[i][j] = 2 + lps(s, i+1, j-1,mem);

        }else{
        mem[i][j] = max(lps(s, i+1, j,mem), lps(s, i, j-1,mem));}
        return  mem[i][j];
    }
};
