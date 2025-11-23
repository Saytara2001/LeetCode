class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> rem1, rem2;
        for(auto num: nums) {
            sum += num;
            if(num % 3 == 1) rem1.push_back(num);   
            if(num % 3 == 2) rem2.push_back(num);
        }
        
        sort(begin(rem1), end(rem1));
        sort(begin(rem2), end(rem2));
        
        int cur = 0;
        if(sum % 3 == 1) {
            // remove 1 element from rem1 or 2 elements from rem2
            if(rem1.size())
                cur = sum - rem1[0];
            
            if(rem2.size() > 1)
                cur = max(cur, sum - (rem2[0] + rem2[1]));
            sum = cur;
        }else if(sum % 3 == 2) {
            
            // remove 2 elements from rem1 or 1 element from rem2
            if(rem1.size() > 1)
                cur = sum - rem1[0] - rem1[1];
            
            if(rem2.size())
                cur = max(cur, sum - rem2[0]);
            
            sum = cur;
        }
        
        return sum;    
    }
};