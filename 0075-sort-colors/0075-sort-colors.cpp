class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = 0;
        for(auto it: nums) {
            r += it == 0;     
            w += it == 1;    
            b += it == 2;
        }
        for(auto& it: nums) {
            if(r-- > 0) it = 0;
            else if(w-- > 0) it = 1;
            else it = 2;
        }
    }
};