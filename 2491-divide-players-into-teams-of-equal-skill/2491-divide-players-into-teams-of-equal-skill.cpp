class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n = size(skill);
        sort(begin(skill), end(skill));
        
        int r = n - 1;
        int target = skill[0] + skill.back();
        long long res = 0;
        
        for(int i = 0 ; i < r; i++, --r) {
            if(target != skill[i] + skill[r])
                return -1;
            res += 1LL * skill[i] * skill[r];
        }
        
        return res;
    }
};