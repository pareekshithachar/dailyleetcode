class Solution {
public:
    static int countbits(int n){
        int count =0;
        while (n) {
            n &= (n - 1);
            count++;
    
        }
        
        return count;
    }

    static bool compare(int a, int b){
        int bitsA = countbits(a);
        int bitsB = countbits(b);
        if(bitsA == bitsB) return a < b;
        return bitsA < bitsB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);

       return arr;
    }
};