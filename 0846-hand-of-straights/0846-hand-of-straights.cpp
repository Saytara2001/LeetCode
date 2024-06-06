class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(groupSize == 1)
            return true;
        multiset<pair<int, int>> st;
        sort(begin(hand), end(hand));
        for(int i = 0; i < size(hand); i++) {
            auto it = st.lower_bound({hand[i] - 1, 0});
            if(it == end(st) or it->first != hand[i] - 1) {
                st.insert({hand[i], 1});
            }else {
                int val = hand[i];
                int cnt = it->second + 1;
                st.erase(it);
                if(cnt != groupSize) {
                    st.insert({val, cnt});
                }
            }
        }
        return st.empty();
    }
};