class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        int n = nums.size();      
        if(n < 2) return {};
        if(n == 2){
            return nums[0] ==  nums[1] ? vector<int>{nums[0]} : vector<int>{};
        }
        for(int i =0;i<n;i++){
            nums[(nums[i]-1)%n] +=  n;
        }
        vector<int>ans;
        for(int i =0;i<n;i++){
            if((nums[i]-1)/n >= 2){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};

// [30,12,15,20,19,1,11,4,13,27]