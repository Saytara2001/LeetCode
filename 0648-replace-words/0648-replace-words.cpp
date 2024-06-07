class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> st;
        for(auto it: dictionary) {
            st.insert(it);
        }
        string res = "";
        int sz = size(sentence);
        string t = "";
        for(int i = 0; i < sz; i++) {
            if(sentence[i] != ' ') {
                t += sentence[i];
                if(st.find(t) != end(st)) {
                    res += t + " ";
                    t = "";
                    while(i < sz and sentence[i] != ' ') i++;
                }
            }else {
                res += t + " ";
                t = "";
            }
        }
        if(t.size()) res += t;
        else res.pop_back();
        return res;
    }
};