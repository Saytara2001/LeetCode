class Solution {
public:
    int par[26];
    void init(){
        iota(par, par+26, 0);
    }
    int findParent(int u){
        if(u == par[u]) return u;
        return par[u] = findParent(par[u]);
    }
    void join(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u != v){
            if(u > v) swap(u, v);
            par[v] = u;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        init();
        for(int i = 0; i < s1.size(); i++){
            join(s1[i]-'a', s2[i]-'a');
        }
        string ans = "";
        for(int i = 0; i < baseStr.size(); i++){
            ans += (char)(findParent(baseStr[i]-'a')+'a');
        }
        return ans;
    }
};