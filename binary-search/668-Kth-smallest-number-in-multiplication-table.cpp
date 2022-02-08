class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low =1, high = m*n;
        
        while(low < high){
            
            int mid = low + (high - low)/2;
            if(isFeasible(m, n, k, mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
    
    
    bool isFeasible(int m , int n, int k, int smallest){
        int count =0;
        for(int i=1; i<=m; i++){
            int add = min( smallest/i, n);
            if( add == 0){
                break;
            }
            count += add;
        }
        
        return count >= k;
    }
};

