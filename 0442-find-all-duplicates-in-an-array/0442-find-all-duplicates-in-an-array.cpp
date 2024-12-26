class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        int n = nums.size();      
        vector<int>ans;
        for(int i =0;i<n;i++){
            int a = abs(nums[i])-1;
            if(nums[a] < 0){
                ans.push_back(a+1);
            }else{
                nums[a] *=-1;
            }
        }
        return ans;
    }
};

// [30,12,15,20,19,1,11,4,13,27]