class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n){
            int set = n&1;
            n = n >>1;
            if(set){
                if(n) return false;
                return true;
            }
        }
        return false;
    }
};