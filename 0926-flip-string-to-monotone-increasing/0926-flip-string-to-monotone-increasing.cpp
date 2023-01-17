class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res = 0, cnt1 = 0;
        for(auto ss:s){
            if(ss == '1') 
                cnt1++;
            else
                res = min(res+1, cnt1);
        }
        return res;
    }
};