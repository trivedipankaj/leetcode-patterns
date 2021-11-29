class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
       int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n));
        int res =0;
        for(int i=0; i< m; i++){
            for(int j=0; j< n; j++){
               dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
               
                if(i>0 && j>0 && matrix[i][j] == '1'){
                    dp[i][j]  = 1+ min( dp[i-1][j] , min(dp[i][j-1], dp[i-1][j-1]));
                   
                 }
                 res = max(res, dp[i][j]);
          }
        }
        return res*res;
      }
};
