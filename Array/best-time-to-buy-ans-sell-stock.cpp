class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,start_price=prices[0];
        for(int i=0;i<prices.size();i++){
            profit=max(profit,prices[i]-start_price);
            start_price=min(prices[i],start_price);
        }
        return profit;
    }
};