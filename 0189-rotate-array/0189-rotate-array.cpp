class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        for(int i = 0; i<n-k;i++){
            nums.push_back(nums[i]);
        }
        nums.erase(nums.begin(),nums.begin()+(n-k));
    }
};