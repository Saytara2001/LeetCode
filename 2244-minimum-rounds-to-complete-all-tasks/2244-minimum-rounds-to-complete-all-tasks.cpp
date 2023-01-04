class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto task:tasks) mp[task]++;
        int ans = 0;
        for(auto it:mp){
            if(it.second == 1) return -1;
            ans += (it.second+2)/3;
        }
        return ans;
    }
};