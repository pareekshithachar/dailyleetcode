class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = nums.size()-1;
        for(int i = nums.size()-1;i>=0;i--){
            if(nums[i] == 0){
                int j = i+1;
                while(j<=k){
                    nums[j-1] = nums[j];
                    j++;
                }
                nums[k] = 0;
                k--;
            }
        }
    }
};