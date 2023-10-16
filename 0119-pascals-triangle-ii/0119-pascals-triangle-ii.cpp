class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pas {1};
        for(int i = 0; i < rowIndex; i++) {
            vector<int> cur {1};
            for(int j = 0; j < size(pas) - 1; j++) {
                   cur.push_back(pas[j] + pas[j+1]);
            }
            cur.push_back(1);
            pas = cur;
        }
        
        return pas;
    }
};