class Solution {

    #define MOD 1000000007
public:
   
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long ans =0;

        unordered_map<int,long>count;

        for(int i=0;i<arr.size();i++){
            count[arr[i]] = 1;
            for(int j =0;j<i;j++){

                if(arr[i] % arr[j] == 0){
                    count[arr[i]] = (count[arr[i]] +  (count[arr[j]] * count[arr[i]/arr[j]]))%MOD;
                }

            }
            ans = (ans+ count[arr[i]])%MOD;
        }

        return ans;

    }
};