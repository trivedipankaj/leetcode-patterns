class Solution {
public:
    int maxProfit(vector<int>& prices) {
          int n = prices.size();
		vector<int>buy(n, 0);
		vector<int>sell(n, 0);

		buy[0] = -prices[0], sell[0] = 0;
        int sell2 = 0;
		for (int i = 1; i < n; i++) {
			int tmp = sell[i-1];
			sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
            buy[i] = max(buy[i-1], sell2-prices[i]);
            sell2 = tmp;
		}

		return sell[n-1];
    }
};
