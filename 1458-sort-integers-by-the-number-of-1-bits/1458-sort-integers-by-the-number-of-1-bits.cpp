class Solution {
public:
    int countbits(int n){
        int count =0;
        while (n) {
            n &= (n - 1);
            count++;
    
        }
        
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        vector<vector<int>>ans(15);

        for(auto x: arr){
            ans[countbits(x)].push_back(x);
        }
        
        vector<int>result;
        for(auto x: ans){
            for(auto y : x){
                result.push_back(y);
            }
        }
        return result;
    }
};