class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>r(n,n);
        vector<int>l(n,-1);

        stack<int>st;
        st.push(n-1);
        for(int i = n-2;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) r[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(0);
        for(int i = 1;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) l[i] = st.top();
            st.push(i);
        }
         int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, heights[i]*(r[i] - l[i] -1));
        }
        return  ans;
    }

   
};