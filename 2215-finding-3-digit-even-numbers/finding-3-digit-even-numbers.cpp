class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> st;
        vector<int> freq(10);
        for(auto d: digits) {
            ++freq[d];
        }
        for(int a = 1; a < 10 ; a++) {
            if(freq[a] > 0) {
                --freq[a];
                for(int b = 0; b < 10; b++) {
                    if(freq[b] > 0) {
                        --freq[b];
                        for(int c = 0; c < 10; c += 2) {
                            if(freq[c] > 0) {
                                int x = a * 100 + b * 10 + c;
                                st.insert(x);
                            }
                        }
                        ++freq[b];
                    }
                }
                ++freq[a];
            }
        }

        return vector<int>(begin(st), end(st));
    }
};