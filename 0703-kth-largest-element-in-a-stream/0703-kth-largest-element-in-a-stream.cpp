class KthLargest {
public:
    priority_queue<int> pq;
    int Kth;
    KthLargest(int k, vector<int>& nums) {
        Kth = k;
        for(auto it: nums) {
            pq.push(-it);
        }
        while(pq.size() > k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(-val);
        if(pq.size() > Kth)
            pq.pop();
        return -pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */