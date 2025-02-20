class Solution {
public:
    string solve(string s, int n, set<string>&st){
        if(s.length() >= n){
            if(!st.count(s)) return s;
            return "";
        }
        string ans = "";
        for(int i =0;i<2;i++){
            s+= (i+'0');
            ans = solve(s,n,st);
            s.pop_back();
            if(ans != "") return ans;
        }
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string s = "";
        set<string>st;
        int n = nums[0].length();
        cout<<n<<" ";
        for(auto x : nums) st.insert(x);
        
        return solve(s,n,st);;
    }
};