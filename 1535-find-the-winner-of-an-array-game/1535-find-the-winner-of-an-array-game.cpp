class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = size(arr);
        if(k >= n)
            return *max_element(begin(arr), end(arr));
        deque<int> dq;
        for(auto it: arr)
            dq.push_back(it);
        
        int lst = -1;
        int wins = 0;
        while(wins < k) {
            int a = dq.front();
            dq.pop_front();
            int b = dq.front();
            dq.pop_front();
            if(a < b)
                swap(a, b);
            if(lst == a)
                wins++;
            else
                wins = 1;
            lst = a;
            dq.push_front(a);
            dq.push_back(b);
        }
        return lst;
    }
};