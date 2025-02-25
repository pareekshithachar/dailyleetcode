class Solution {
public:
    int findCostWOBob(unordered_map<int,vector<int>>&mp, int node,vector<int>&parent,vector<int>&costwobob,vector<int>& amount){
        
        int cost = INT_MIN;
        for(auto x : mp[node]){
            if(x != parent[node]){
                parent[x] = node;
                cost= max(cost,findCostWOBob(mp,x,parent,costwobob,amount));
            }
        }
        if(cost == INT_MIN) cost = 0;
        cost+=amount[node];
        return costwobob[node] = cost;
    }
    int findCostWithoutBobIntersection(unordered_map<int,vector<int>>&mp,vector<int>&costwobob,int cur,int nodeToIgnore, vector<int>&parent){
        int cost = -1e9;
        int child_count = 0;
        for(auto x : mp[cur]){
            if(x == parent[cur]){
                continue;
            }
            child_count++;
            if(x == nodeToIgnore) continue;
            cost = max(costwobob[x],cost);
        }
        if (child_count == 0) return 0;

        return cost;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        unordered_map<int,vector<int>>mp;
        int n = amount.size();
        for(auto x : edges){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        vector<int>parent(n,-1);
        vector<int>costwobob(n,INT_MIN);
        findCostWOBob(mp,0,parent,costwobob,amount);
        vector<int>pathofbob;
        while(bob!=-1){
            pathofbob.push_back(bob);
            bob  = parent[bob];
        }
        reverse(pathofbob.begin(),pathofbob.end());
        int ans = INT_MIN;
        n= pathofbob.size();
        for(int i =0, cost=0;i<pathofbob.size();i++){
            if(i < n-1-i){
                cost += amount[pathofbob[i]];
            }
            if( i == n-1-i){
                cost += amount[pathofbob[i]]/2;
            }
            ans = max(ans,cost + findCostWithoutBobIntersection(mp,costwobob,pathofbob[i],i+1 < n ?pathofbob[i+1] : -1,parent));
        }

        return ans;
    }
};