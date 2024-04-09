class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = size(tickets);
        int front = (k + 1) * tickets[k];
        int back = (n - k - 1) * (tickets[k] - 1);
        int sum = front + back;
        for(int i = 0; i < n; i++) {
            if(i <= k) {
                if(tickets[i] - tickets[k] < 0) 
                    sum += tickets[i] - tickets[k];
            }else {
                if(tickets[i] - (tickets[k] - 1) < 0) 
                    sum += tickets[i] - (tickets[k] - 1);
            }
        }
        return sum;
    }
};