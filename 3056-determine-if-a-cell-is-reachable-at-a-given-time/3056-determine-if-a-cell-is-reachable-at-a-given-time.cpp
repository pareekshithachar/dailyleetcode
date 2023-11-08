class Solution {
public:
 
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        if((abs(sx - fx) > t  )||( abs(sy-fy) > t )) return false;
        if(sx == fx && sy==fy && t == 1) return false;
        return true;
        

    }
};