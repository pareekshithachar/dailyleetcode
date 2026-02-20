class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int ans = 0;
        for(int i = 0;i<32;i++){
            int l = 1&(a>>i);
            int r = 1&(b>>i);
            int temp = l + r;
            if(carry == 1){
                temp+= 1;
                carry = 0;
            }
            if(temp == 2){
                temp = carry ? 1 : 0;
                carry = 1;     
            }
            ans = ans|(temp<<i);
        }
        return ans;
    }
};