class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st = 0, n = gas.size(), sum = 0, total = 0;
        for(int i = 0; i < n; i++){
            
            sum += gas[i] - cost[i];
            
            if(sum < 0){
                total += sum;
                sum = 0;
                st = i+1;
            }
        }
        st %= n;
        total += sum;
        return total >= 0 ? st : -1;
    }
};