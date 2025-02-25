class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long ans = 0;
        int odd = 0,even=0;
        int sum = 0;
        for(int x : arr){
            sum+=x;
            if(sum%2){
                ans+= even+1;
                odd++;
            }else{
                ans+=odd;
                even++;
            }
        }
        return ans%1000000007;
    }
};