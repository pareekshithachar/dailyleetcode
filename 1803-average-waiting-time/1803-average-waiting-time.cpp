class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time;
        int n = customers.size();
        vector<int>wait(n,0);
        time = 0;
        int i =0;
        while(i < n){
            if(time < customers[i][0]){
                time = customers[i][0];
            }
            time+= customers[i][1];
            wait[i] = time - customers[i][0];
            i++;
            
        }
        long sum = 0;
        for(auto x : wait){
            sum+= x;
        }
        double ans = sum*1.0/n;
        return ans;
    }
};