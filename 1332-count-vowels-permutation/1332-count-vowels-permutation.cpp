class Solution {
    #define MOD 1000000007
public:
    
    vector<string>vec;
    vector<vector<int>>dp;
    unordered_map<string,int>mp;
    bool ispos(string ch, string newch){
        if(ch == "a" && newch != "e"){
            return false;
        }else if(ch == "e" && !(newch == "a" || newch == "i")){
            return false;
        }else if(ch == "i" && newch == "i"){
            return false;
        }else if(ch == "o" && !(newch == "i" || newch == "u")){
            return false;
        }else if(ch == "u" && newch!="a"){
            return false;
        }
        return true;
    }
    int solve(int n, string cur){
        if(n <= 0){
            return 1;
        }
        int ans = 0;
        if(dp[n][mp[cur]] != -1){
            return dp[n][mp[cur]];
        }
        for(int i = 0;i<5;i++){
            if(ispos(cur,vec[i])){
                ans = ans%MOD + solve(n-1,vec[i])%MOD;
            }
        }

        return dp[n][mp[cur]] = ans%MOD;
    }
    int countVowelPermutation(int n) {
        vec = {"a","e","i","o","u"};
        mp["a"] = 0;
        mp["e"] = 1;
        mp["i"] = 2;
        mp["o"] = 3;
        mp["u"] = 4;
        dp.resize(n+1,vector<int>(5,-1));
        return solve(n,"");
    }
};