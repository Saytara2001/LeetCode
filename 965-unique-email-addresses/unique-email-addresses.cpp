class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;
        auto get  = [&](string &s) {
            int n = s.size();
            string gen = "";
            for(int i = 0; i < n and s[i] != '@'; i++) {
                if(s[i] == '.') continue;
                if(s[i] == '+') break;
                gen += s[i];
            }
            int pos = s.find('@');
            for(int i = pos; i < n; i++) gen += s[i];
            cout << gen << endl;
            return gen;
        };
        for(auto email: emails) {
            unique.insert(get(email));
        }
        return unique.size();
    }
};