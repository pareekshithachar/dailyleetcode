class Solution {
public:
    string removeOccurrences(string s, string part) {
        auto itr = s.find(part) ;
        while(itr != string::npos){
            s.erase(itr,part.length());
            itr = s.find(part);
        }
        return s;
    }
};