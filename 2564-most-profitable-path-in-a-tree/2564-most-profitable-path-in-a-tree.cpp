class Solution {
public:
    int dfs(vector<vector<int>>&mp, int node, vector<int>&price,  unordered_map<int,int>&parent,vector<int>&amount){
        // if(mp[node].size() == 1 && parent[node] == mp[node][0]) return amount[node];
        
        int ans = amount[node];
        int nextbest = INT_MIN;
        for(auto x : mp[node]){
            
            if(parent.find(x) == parent.end()){
                
                parent[x] = node;
                nextbest = max(nextbest,dfs(mp,x,price,parent,amount));
            }   
        }
        nextbest = nextbest == INT_MIN? 0 : nextbest;
        return price[node] = ans+ nextbest;
    }
    int FindBestExceptSpecificChild (vector<vector<int>>&g,unordered_map<int,int>&parent,vector<int>&price,int root, int child_to_skip) {
        int result = -1e9;
        int child_count = 0;
        
        for (auto child : g[root]) {
            if (child == parent[root]) continue;
            
            child_count ++;
            if (child == child_to_skip) continue;
            
            result = max (result, price[child]);
        }
        
        if (child_count == 0) return 0;
        return result;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // unordered_map<int, list<int>>mp;
        vector<vector<int>>mp(amount.size());
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);  
        }
        unordered_map<int,int>parent;
        parent[0] = -1;
        vector<int>price(mp.size(),-1);
        // price[0] = amount[0];
        dfs(mp,0,price,parent,amount);
        for(auto x : price){
            cout<<x;
        }
        vector<int>path;
        while(bob != -1){
            path.push_back(bob);
            bob = parent[bob];
        }
        reverse(path.begin(),path.end());
        int result = INT_MIN;
        int n = path.size();
        for (int ind = 0, cost_till_now = 0; ind < n; ind ++) {
            bool is_alice_first = (ind < n-1-ind);
            bool is_same_arrival = (ind == n-1-ind);
            
            if (is_alice_first)  cost_till_now += amount[path[ind]];
            if (is_same_arrival) cost_till_now += amount[path[ind]] / 2;
            
            result = max (
                result, 
                cost_till_now + FindBestExceptSpecificChild (mp,parent,price,path[ind], ind+1 < n? path[ind+1] : -1)
            );
        }
        
        return result;
    }
};