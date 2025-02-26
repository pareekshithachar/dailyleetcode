class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=0;
        int prefix=0;
        int minprefix = 0;
        int maxprefix = 0;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            minprefix = min(prefix,minprefix);
            maxprefix = max(prefix,maxprefix);
        }
        
        return maxprefix-minprefix;
    }
};