class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char, string> ps;
        unordered_map<string, char> sp;

        int m = p.size();
        int n = s.size();
        int i = 0;
        int j = 0;
        
        while(i< m && j < n){
            string str="";
            while(j < n && s[j] != ' '){
                str += s[j];
                j++;
            }

            if(ps.find(p[i]) == ps.end() && i < m){
                ps[p[i]] = str;
            }else if(ps.find(p[i])!= ps.end() && ps[p[i]] != str){
                return false;
            }

            if(sp.find(str) == sp.end()){
                sp[str] = p[i];
            }else if(sp.find(str) != sp.end() && sp[str] != p[i]){
                return false;
            }
            i++;
            j++;
        }
        if(i != m || j !=n+1) return false;

        return true;

    }
    
};