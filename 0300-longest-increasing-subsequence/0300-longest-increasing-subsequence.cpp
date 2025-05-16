class Solution {
public:
    int solve(vector<int>&nums, int idx, int prev,vector<vector<int>>&dp){
        if(idx == nums.size()){
            return 0;
        }
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int take = INT_MIN;
        if(prev == -1 || nums[prev] < nums[idx]){
            take = 1 + solve(nums,idx+1,idx,dp);
        }
        int notTake = solve(nums,idx+1,prev,dp);
        return dp[idx][prev+1] = max(take,notTake);

    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(nums,0,prev,dp);
    }
};