class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto num: nums) {
            v.push_back(to_string(num));
        }
        sort(begin(v), end(v), [&] (auto& a, auto& b){
            string gen1 = a + b;
            string gen2 = b + a; 
            if(gen1 > gen2) return true;
            return false;
        });
        string ans = "";
        for(auto it: v) {
            ans += it;
        }
        if(count(begin(ans), end(ans), '0') == ans.size())
            ans = "0";
        return ans;
    }
};