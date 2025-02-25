#define MOD 1000000007
class Solution {

public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        vector<int>presum(n,0);
        presum[0] = arr[0];
        for(int i=1;i<arr.size();i++){
            presum[i] = presum[i-1]+arr[i];
        }
        int evensum=0;
        int oddsum=0;
        for(int i =0;i<n;i++){
            if(presum[i]%2){
                oddsum++;
            }else{
                evensum++;
            }
            if(presum[i]%2){
                ans += (evensum+1)%MOD;
            }else{
                ans+= oddsum%MOD;
            }
            ans=ans%MOD;
        }
        return ans;
        
    }
};


//1 5 1 3 5 6
//1 6 7 10 15 21