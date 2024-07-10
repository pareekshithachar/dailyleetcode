class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = time/(n-1);
        int per = time%(n-1);
        
        return dir%2 == 0? per+1 : n-per;

    }
};