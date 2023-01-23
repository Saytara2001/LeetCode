class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> freq(10005, 0);
        vector<bool> isTrust(10005, 0);
        for(auto tt:trust){
            isTrust[tt[0]] = 1;
            freq[tt[1]]++;
        }
        int any = 0, ans = -1;
        for(int i = 1; i <= n; i++){
            if(freq[i] == n-1 and !isTrust[i]) ans = i, any++;
        }
        return any == 1 ? ans : -1;
    }
};