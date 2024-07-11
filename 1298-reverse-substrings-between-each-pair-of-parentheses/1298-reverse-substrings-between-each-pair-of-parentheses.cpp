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
        int dir =1;
        int idx = 0;
        // ( a b c d )
        // 0 1 2 3 4 5
        while(idx < n){

            if(s[idx] == '('){
                dir = -dir;
                idx = pair[idx];
                
            }else if(s[idx] == ')'){
                dir = -dir;
                idx = pair[idx];
                
            }else{
                ans+= s[idx];
                
            }
           idx += dir;
        }
        return ans;
    }
};