class Solution {
private:
    vector<int> weights;
    int numDays;
    int totalWeights;
    int maxWeight;
public:
    int shipWithinDays(vector<int>& weights, int days) {
        setWeights(weights);
        setNumDays(days);
        setWeights();
        
        int low = maxWeight, high = totalWeights;
        
        while(low <high){
            int mid = low + (high - low)/2;
            
            if(isFeasible(mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
    
    void setWeights(vector<int> w){
        this->weights = w;
    }
    
    void setNumDays(int days){
        this->numDays = days;
    }
    
    void setWeights(){
        int mx = 0;
        int total =0;
         for(int weight : weights){
             mx = max(mx, weight);
             total += weight;
         }
        
        maxWeight = mx;
        totalWeights= total;
    }
    
    bool isFeasible(int capacity){
        
        int total =0;
        int days = 1;
        for(int weight : weights){
            total += weight;
            if(total > capacity){
                days++;
                total = weight;
            }
            if(days > numDays){
                return false;
            }
        }
        return true;
    }
};

