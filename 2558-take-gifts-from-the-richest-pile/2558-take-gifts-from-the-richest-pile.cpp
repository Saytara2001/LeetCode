class Solution {
public:
    long long pickGifts(vector<int>& v, int k) {
        priority_queue<int> pq;
        long long take = 0, i = 0;
        
        for(auto vv:v) {
            pq.push(vv);
        }
        
        while(!pq.empty()) {
            int top = pq.top();
            pq.pop();
            if(i < k) {
                int f = floor(sqrt(top));
                if(f > 0)
                    pq.push(f);
            }else {
                 take += top;
            }
            i++;
        }
        return take;
    }
};