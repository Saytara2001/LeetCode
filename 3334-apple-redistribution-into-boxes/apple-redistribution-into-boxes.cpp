class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(begin(apple), end(apple), 0);
        sort(begin(capacity), end(capacity), greater<>());
        int box = 0;
        for(int i = 0; i < capacity.size() and sum > 0; i++) {
            sum -= capacity[i];
            ++box;
        }
        return box;
    }
};