class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxRate = 0;
         for(int pile: piles){
             maxRate = max(maxRate, pile);
         }
        int low = 1, high = maxRate;
        
        while(low < high){
            int mid = low +(high -low)/2;
            
            if(isFeasible(piles, h, mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        
        return low;
    }
    
    
    bool isFeasible(vector<int>& piles, int h, int rate){
        int hours =0;
        for(int pile: piles){
            hours += pile/rate;
            if(pile %rate !=0){
                hours++;
            }
            if(hours > h){
                return false;
            }
        }
        return true;
    }
};
