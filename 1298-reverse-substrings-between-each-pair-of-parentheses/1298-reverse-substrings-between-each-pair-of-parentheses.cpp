class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }
            if(s[i] == ')'){
                int startidx = st.top();
                st.pop();
                int endidx = i;
                reverse(s.begin()+startidx, s.begin() + endidx + 1);
            }
        }
        string ans = "";
        for(int i =0;i<s.size();i++){
            if(s[i]!= '(' && s[i] != ')') ans += s[i];
        }
        return ans;
    }
};