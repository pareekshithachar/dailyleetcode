class Solution {
public:
    bool check(vector<int>& nums) {
        bool peakfound = false;
        int n = nums.size();
        for(int i =1;i<n;i++){
            if(nums[i-1] > nums[i]){
                if(peakfound) return false;
                peakfound= true;
            }
        }
        if(nums[n-1] > nums[0]){
            if(peakfound) return false;
            peakfound= true;
        }
        return true;
    }
};