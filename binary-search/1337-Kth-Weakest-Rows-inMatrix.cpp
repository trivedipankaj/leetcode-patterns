class Solution {
private:
   
public:
    
     struct compare{
      bool operator()( pair<int,int> a,  pair<int,int> b){
          if(a.first == b.first){
              return a.second < b.second;
          }
          return a.first < b.first;
      }  
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> q;
    vector<int> res;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        for(int i=0; i<mat.size(); i++){
            int c = getBorder(mat[i]);
             q.push({c,i});
             if(q.size() > k){
                 q.pop();
             }
        }
        
        while(!q.empty()){
            res.push_back(q.top().second); q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    int getBorder(vector<int> nums){
        int low = 0;
        int high = nums.size() ;
        while(low < high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == 1){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        
        return low;
    }
};
