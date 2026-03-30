class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // iterate thru the array with index i
        // profit = sell - buy
        // For each sell price
        // What is the minimum buy price?
        // min buy price
        int len = prices.size();
        vector<int> min_buy_price(len, 10000);
        int temp = 10000;
        for (int i = 1; i < len; i++) {
            temp = min(temp, prices[i-1]);
            min_buy_price[i] = temp;
        }
        vector<int> profits(len, 0);
        for (int i = 0; i < len; i++) {
            profits[i] = prices[i] - min_buy_price[i];
        }
        int max_profit = 0;
        for (int i = 0; i < len; i++) {
            max_profit = max(max_profit, profits[i]);
        }
        return max_profit;
    }
};
