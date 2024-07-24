class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto translate = [&](int num)->int{
            string digits = to_string(num);
            for(auto& x: digits){
                x = '0'+mapping[x-'0'];
            }
            return stoi(digits);
        };
        unordered_map<int,int>number_mapping;
        for(int num : nums){
            if(number_mapping.find(num) == number_mapping.end()){
                number_mapping[num] = translate(num);
            }
        }
        sort(nums.begin(),nums.end(),[&](int a, int b){
            return number_mapping[a] < number_mapping[b];
        });
        return nums;
    }
};