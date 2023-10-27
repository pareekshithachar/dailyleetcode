class Solution {
public:

    string longestPalindrome(string s) {
        int bestl = 0,bestr = 0;
        for(int i = 0;i<s.size();i++){
            int l = i;
            int k = i;
            while(l >= 0 && k < s.size() && s[l] == s[k]){
                if(bestr - bestl <= k-l){
                    bestr = k;
                    bestl = l;
                }
                l--;
                k++;
            }
            l=i;
            k=i+1;
            while(l >= 0 && k < s.size() && s[l] == s[k]){
                if(bestr - bestl <= k-l){
                    bestr = k;
                    bestl = l;
                }
                l--;
                k++;
            }
        }

        return s.substr(bestl,bestr-bestl+1);
    }
};