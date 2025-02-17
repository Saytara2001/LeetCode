class Solution {
public:
    void rec(string gen, string tiles, set<string>& st, vector<bool> vis) {

        if(gen.size()) st.insert(gen);

        for(int j = 0; j < size(tiles); j++) {
            if(!vis[j]) {
                vis[j] = true;
                rec(gen + tiles[j], tiles, st, vis);
                vis[j] = false;
            }
        }

    }
    int numTilePossibilities(string tiles) {
        set<string> st;
        vector<bool> vis(size(tiles));
        rec("", tiles, st, vis);
        return int(st.size());
    }
};