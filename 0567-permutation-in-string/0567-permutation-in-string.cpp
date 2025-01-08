class Solution {
public:
    

    bool checkInclusion(string s1, string s2) {
        vector<int>arr(26,0);
        if(s1.length() > s2.length()) return false;
        for(auto  x: s1) arr[x-'a']++;
        vector<int>count(26,0);
        for(int i =0;i<s1.size();i++){
            count[s2[i]-'a']++;
        }
        int k =s1.size();
        if(count == arr) return true;
        for(int i = k;i<s2.size();i++){
            count[s2[i]-'a']++;
            count[s2[i-k]-'a']--;
            if(count==arr) return true;
        }
        return false;
    }
};