class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        int n = s.length();
        vector<int>pair(n);
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            if(s[i]==')'){
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        string ans= "";
       for(int idx = 0,dir = 1;idx <n;idx+=dir){
            if(s[idx] == '(' || s[idx] == ')'){
                idx = pair[idx];
                dir = -dir;
            }else{
                ans += s[idx];
            }
       }
        return ans;
    }
};