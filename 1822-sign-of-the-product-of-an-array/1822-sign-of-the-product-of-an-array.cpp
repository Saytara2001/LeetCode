class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for(auto vv:nums) {
            
            if(vv == 0)
                return 0;
            
            if(vv < 0)
                neg++;
            
        }
        return neg&1 ? -1 : 1;
    }
};