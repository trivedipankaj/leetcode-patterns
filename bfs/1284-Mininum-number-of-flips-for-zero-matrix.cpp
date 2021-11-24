class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        string target = "";
        string source= "";
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                source += to_string(mat[i][j]);
                target += to_string(0);
            }
        }
       
        queue<string> q;
        unordered_map<string, bool> visited;
        
        q.push(source);
        int step=0;
        
        while(!q.empty()){
            int k = q.size();
            while(k--){
                string curr = q.front(); q.pop();
                if(curr == target) { 
                    return step;
                }
               
                for(int i=0; i<curr.size(); i++){
                   auto np = nextPoints(i, m, n);
                    auto tmp = flip(curr, i, np);
                     
                     if(!visited[tmp]){
                         visited[tmp] = true;
                        q.push(tmp);
                     }
                }
            }
            step++;
        }
        return -1;
    }
    
    
   vector<int> nextPoints(int index, int m, int n){
         vector<int> res;
         auto curr = getMatrix(index, n);
         int dx[] = {1, 0 , -1 , 0};
         int dy[] = { 0 , 1, 0, -1};

         for(int i=0; i<4; i++){
             int x = curr.first + dx[i];
             int y = curr.second + dy[i];
             if( x >=0 && x < m && y >=0 && y< n){
                 res.push_back(getIndex(x, y,n));
             }
         }
         return res;
     }

     int getIndex(int row, int col, int n){
         return n*row + col;
     }

     pair<int, int> getMatrix(int index, int n){
         return {index/n, index%n};
     }

     string flip(string s, int index,  vector<int> pos){
         string tmp = s;
         tmp[index] = tmp[index] == '0' ? '1' : '0';
         for(int i=0; i< pos.size(); i++){
            if(tmp[pos[i]] == '0') tmp[pos[i]] ='1';
            else if(tmp[pos[i]] == '1') tmp[pos[i]] = '0'; 
         }
         return tmp;
     }
    
};
