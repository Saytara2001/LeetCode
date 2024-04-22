class Solution {
public:
    char next(char c) {
        c = (c - '0' + 1) % 10;
        return (c + '0');
    }
    char prev(char c) {
        c = (c - '0' - 1 + 10) % 10;
        return (c + '0');
    }
    int openLock(vector<string>& deadends, string target) {
        
        if(target == "0000") return 0;
        
        map<string , bool> dead;
        for(auto it: deadends) {
            dead[it] = 1;
        }
        
        string a = "0000";
        map<string , bool> vis;
        queue<string> q;
        
        q.push(a);
        vis[a] = true;
        int cnt = 0;
        
        while(q.size()) {
            
            int sz = q.size();
            cnt++;
            
            while(sz--) {
                
                a = q.front();
                q.pop();
                if(dead.count(a)) continue;
                
                for(int i = 0; i < 4; i++) {
                    string tmp = a;

                    tmp[i] = next(tmp[i]);
                    if(!vis.count(tmp) and !dead.count(tmp)) {
                        q.push(tmp);
                        vis[tmp] = 1;
                        if(tmp == target) return cnt;
                    }
                    tmp = a;
                    tmp[i] = prev(tmp[i]);
                    if(!vis.count(tmp) and !dead.count(tmp)) {
                        q.push(tmp);
                        vis[tmp] = 1;
                        if(tmp == target) return cnt;
                    }
                }
            }
        }
        return -1;
        
    }
};