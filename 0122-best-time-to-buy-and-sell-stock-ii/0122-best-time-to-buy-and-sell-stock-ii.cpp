class Solution {
public:
    int solve(vector<int>&prices, int bought, int idx, vector<vector<int>>&dp){
        if(idx >= prices.size()) return 0;
        if(dp[bought][idx] != -1 ) return dp[bought][idx];
        int profit = INT_MIN;
        if(bought == 1){
            int sell = solve(prices,0,idx+1,dp) + prices[idx];
            int dontsell = solve(prices,1,idx+1,dp);
            profit = max(sell,dontsell);

        }else{
            int buy = solve(prices, 1,idx+1,dp) - prices[idx];
            int dontbuy = solve(prices,0,idx+1,dp);
            profit = max(buy,dontbuy);
        }
        return dp[bought][idx] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(2,vector<int>(prices.size(),-1));
        return solve(prices,0,0,dp);
    }
};