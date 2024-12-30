class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 0;
        vector<int>temp(n,0);
        temp[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            temp[i] = nums[i]+temp[i+1];
        }
        int lsum = 0;
        for(int i=0;i<n;i++){
            if(lsum == (temp[i]-nums[i])){
                return i;
            }
            lsum+= nums[i];
        }
        return -1;
        
    }
};