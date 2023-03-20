class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int need) {
        int can = 0, n = v.size();
        for(int i = 0; i < n; i++) {
            if(!v[i]) {
                //first pos
                if((i+1 < n and !v[i+1] and !i) or n == 1)
                    can++, v[i] |= 1;
                else if(i-1 >= 0 and i+1 < n and !v[i-1] and !v[i+1])
                    can++, v[i] |= 1;
                else if(i-1 >= 0 and !v[i-1] and i == n-1)
                    can++, v[i] |= 1;
            }
        }
        return can >= need;
    }
};