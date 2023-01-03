class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto vv:piles) pq.push(vv);
        while(k and !pq.empty()){
            int top = (pq.top()+1)/2;
            pq.pop();
            if(top) pq.push(top);
            k--;
        }
        long long sum = 0;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            sum += top;
        }
        return sum;
    }
};