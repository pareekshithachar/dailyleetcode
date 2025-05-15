class Solution {
public:
    int solve(vector<int>&prices,int bought, int idx, int limit, vector<vector<vector<int>>>&dp){
        if(idx >= prices.size()) return 0;
        if(dp[bought][limit][idx] != -1) return dp[bought][limit][idx];
        int profit = 0;
        if(!bought){
            int buy = 0;
            if(limit > 0){
                buy = -prices[idx] + solve(prices,1,idx+1,limit-1,dp);
            }
            int dontBuy = solve(prices,0,idx+1,limit,dp);
            profit = max(buy,dontBuy);
        }else{
            int sell = prices[idx] + solve(prices,0,idx+1,limit,dp);
            int dontSell = solve(prices,1,idx+1,limit,dp);
            profit = max(sell,dontSell);
        }

        return dp[bought][limit][idx] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(3,vector<int>(prices.size(),-1)));
        return solve(prices,0,0,2,dp);
    }
};