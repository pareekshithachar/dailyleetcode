class Solution {
public:
    void rotate(vector<vector<int>>& vec) {
        int n = vec.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
               swap(vec[i][j],vec[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(vec[i].begin(), vec[i].end());
        }
    }
};

//0 0 -> 0 ,2
//0 1 -> 1, 2