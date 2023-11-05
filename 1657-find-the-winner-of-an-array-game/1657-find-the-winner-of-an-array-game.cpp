class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        vector<int>greater(arr.size(), 0);

        stack<int>st;
        for(int i=arr.size();i>=0;i--){
            st.push(arr[i]);
        }
        stack<int>st2;
        int count = 0;
        int initial_num = st.top();
        k = min(k, (int)arr.size());
        st.pop();
        while(count < k){

            if(st.empty()){
                while(!st2.empty()){
                    st.push(st2.top());
                    st2.pop();
                }
            }
            int num1 =  st.top();
            st.pop();

            if(num1 < initial_num){
                st2.push(num1);
                count++;
            }else{
                st2.push(initial_num);
                initial_num = num1;
                count = 1;
            }
            
        }
        return initial_num;

    }
};

