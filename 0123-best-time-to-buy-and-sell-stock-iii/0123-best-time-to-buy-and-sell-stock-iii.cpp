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
        int n = prices.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(prices.size()+1,vector<int>(3,-1)));
        for(int i = 0;i<2;i++){
            for(int j = 0;j<3;j++){
                dp[i][n][j] = 0;
            }
        }
        for(int idx = n-1;idx>=0;idx--){
            for(int limit = 0;limit<3;limit++){
                for(int bought = 0;bought < 2;bought++){
                        int profit = 0;
                        if(!bought){
                            int buy = 0;
                            if(limit > 0){
                                buy = -prices[idx] + dp[1][idx+1][limit-1];
                            }
                            int dontBuy = dp[0][idx+1][limit];
                            profit = max(buy,dontBuy);
                        }else{
                            int sell = prices[idx] + dp[0][idx+1][limit];
                            int dontSell = dp[1][idx+1][limit];
                            profit = max(sell,dontSell);
                        }
                        dp[bought][idx][limit] = profit;
                }
            }
        }
        return dp[0][0][2];
    }
};