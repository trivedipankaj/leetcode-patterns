class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string s ="";
        int start;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == 0){
                    start = getIndex(i,j);
                }
                 s += to_string(board[i][j]);
            }
        }
        
       string target = "123450";
        
       queue<pair<string, int>> q;
       unordered_map<string,bool> visited;
        int level=0;
       q.push({s,start});
        while(!q.empty()){
            int n= q.size();
            for(int i=0; i<n; i++){
                auto curr = q.front(); q.pop();
                if(curr.first == target) return level;
                
                if(visited[curr.first]) continue;
                visited[curr.first] = true;
                
                auto next = nextPoints(curr.second);
                for(int k=0; k<next.size(); k++){
                    swap(curr.first, curr.second, next[k]);
                    q.push({curr.first, next[k]});
                    swap(curr.first, curr.second, next[k]);
                }
            }
            level++;
        }
       return -1; 
    }
    
    
    vector<int> nextPoints(int index){
        vector<int> res;
        auto curr = getMatrix(index);
        int dx[] = {1, 0 , -1 , 0};
        int dy[] = { 0 , 1, 0, -1};
        
        for(int i=0; i<4; i++){
            int x = curr.first + dx[i];
            int y = curr.second + dy[i];
            if( x >=0 && x < 2 && y >=0 && y<3){
                res.push_back(getIndex(x, y));
            }
        }
        return res;
    }
    
    int getIndex(int row, int col){
        return 3*row + col;
    }
    
    pair<int, int> getMatrix(int index){
        return {index/3, index%3};
    }
    
    void swap(string &s, int i, int j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
};
