class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=0,negans = 0;
        int psum=0,nsum=0;
        for(int i=0;i<nums.size();i++){
            psum+=nums[i];
            ans=max(psum,ans);
            if(psum < 0){
                psum=0;
            }
            nsum+=nums[i];
            negans = min(negans,nsum);
            if(nsum>0) nsum = 0;
        }
        ans = max(ans,abs(negans));
        return ans;
    }
};