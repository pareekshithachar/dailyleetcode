class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int available_at = 0;
        double total_wait = 0;
        for(auto& x : customers){
            int arrival = x[0];
            int time = x[1];
            available_at = max(available_at, arrival)+time;
            total_wait += available_at - arrival;
        }

        return (double)total_wait/customers.size();
    }
};