class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        for(auto ss: s) {
            freq[ss - 'a']++;
            if(freq[ss - 'a'] > (size(s) + 1) / 2)
                return "";
        }
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < 26 ; i++) {
            if(freq[i])
                pq.push({freq[i], (char)(i + 'a')});
        }
        string res = "";
        while(pq.size()) {
            auto top1 = pq.top();
            pq.pop();
            res += top1.second;
            
            
            if(pq.size()) {
                auto top2 = pq.top();
                pq.pop();
                res += top2.second;
                if(top2.first > 1) {
                    pq.push({top2.first-1, top2.second});
                }
            }
            if(top1.first > 1) {
                pq.push({top1.first-1, top1.second});
            }
            
        }
        return res;
    }
};