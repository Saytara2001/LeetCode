class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        for(auto it: asteroids) {
            v.push_back(it);
            while(v.size() > 1) {
                int ft = v.back();
                v.pop_back();
                int se = v.back();
                v.pop_back();
                if(se > 0 and ft < 0) {
                    if(-ft == se) break;
                    if(-ft > se) {
                        v.push_back(ft);
                    }else {
                        v.push_back(se);
                        break;
                    }
                }else {
                    v.push_back(se); 
                    v.push_back(ft);
                    break;
                }
            }
        }
        return v;
    }
};