typedef long long ll;
class Solution {
public:
    ll dp[1005][1005];
    long long rec(int i,int prev, vector<pair<int,int>>& v){
        if(i >=v.size()) return 0;
        long long &ret = dp[i][prev+1];
        if(~ret) return dp[i][prev+1];
        ll take = 0;
        if( prev == -1 or v[prev].second <= v[i].second){
            return dp[i][prev+1] = max(v[i].second + rec(i+1,i, v) ,rec(i+1,prev, v) );     
        }   
        return dp[i][prev+1] = rec(i+1,prev,v);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v(ages.size());
        for(int i = 0; i< ages.size(); i++){
            v[i].first = ages[i];
            v[i].second = scores[i];

        }
        sort(v.begin(),v.end());
        memset(dp, -1, sizeof dp);
        return rec(0,-1, v);
    }
};