class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> q;
        int n = size(nums);
        vector<int> res;

        for(int i = 0; i < n; i++) {

            // remove out-of-bound
            while(q.size() and q.front() <= i - k) 
                q.pop_front(); 

            // make q monotonic
            while(q.size() and nums[i] > nums[q.back()]) 
                q.pop_back(); 

            q.push_back(i);

            if(i >= k - 1)
                res.push_back(nums[q.front()]);
        }

        return res;
    }
};