class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int i = 0; i < size(stones); i++) {
            q.push(stones[i]);
        }
        while(q.size() > 1) {
            int top = q.top();
            q.pop();
            int top2 = q.top();
            q.pop();
            if(top != top2)
                q.push(top - top2);
        }
        return q.empty() ? 0 : q.top();
    }
};