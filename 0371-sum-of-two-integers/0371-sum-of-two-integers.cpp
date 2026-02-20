class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            int l = (a >> i) & 1;
            int r = (b >> i) & 1;

            // Correct sum bit
            int sum = l ^ r ^ carry;

            // Set result bit
            ans |= (sum << i);

            // Correct carry computation
            carry = (l & r) | (l & carry) | (r & carry);
        }

        return ans;
    }
};
