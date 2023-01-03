class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int idx = 0, mn = 5000;
        for(auto vv:strs){
            mn = min(mn,(int)vv.size());
        }
        for(int k=0;k<mn;k++){
            int cnt=1;
            for(int i=1;i<strs.size();i++){
                if(strs[0][idx] == strs[i][idx]) cnt++;
                else break;
            }
            if(cnt==strs.size()) ans += strs[0][idx++];
            else break;
        }
        return ans;
    }
};