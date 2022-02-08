class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int totalFlowers = bloomDay.size();
        if(totalFlowers < m*k) return -1;
        
        int maxDays = 0;
         for(int day: bloomDay){
             maxDays =max(maxDays, day);
         }

        int low = 1, high =maxDays;
        
        while(low < high){
            
            int mid = low +(high - low)/2;
            if(isPossible(bloomDay, m, k, mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        
        return low;
    }
    
    bool isPossible(vector<int> bloomDay, int m, int k, int days){
        int flowers =0;
        int b =0;
        for(int day: bloomDay){
            if(day <= days){
                flowers++;
            }else{
                flowers  =0;
            }
            if(flowers ==k){
                b++;
                flowers =0;
            }
        }
        return b >=m;
    }
};

