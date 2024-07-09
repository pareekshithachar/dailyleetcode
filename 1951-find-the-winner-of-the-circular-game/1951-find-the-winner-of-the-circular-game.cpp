class Solution {
public:
    int solve(int n, int k, vector<int>&p,int start){
        if(n == 1){
            return p[0];
        }
        int temp = (k+start)%n;
        if(temp == 0){
            temp = n-1;
        }else{
            temp--;
        } 
        p.erase(p.begin()+temp);
        return solve(n-1,k,p,temp);
    }
    int findTheWinner(int n, int k) {
        vector<int>p;
        for(int i =1;i<=n;i++) p.push_back(i);
        return solve(n,k,p,0);
    }
};