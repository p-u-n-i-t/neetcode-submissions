class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max_sell_price=prices[n-1];
        int max_profit=0;
        int current_profit=0;

        for(int i=n-2;i>=0;i--){
            max_sell_price=max(prices[i],max_sell_price);
            current_profit=max_sell_price-prices[i];
            max_profit=max(max_profit,current_profit);
        }

        return max_profit;
    }
};
