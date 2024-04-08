class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ones = count(begin(students), end(students), 1);
        int zeros = count(begin(students), end(students), 0);
        int n = size(sandwiches);
        for(int i = 0; i < n; i++) {
            if(sandwiches[i] == 1) {
                if(ones == 0) return n - i;
                ones--;
            }
            if(sandwiches[i] == 0) {
                if(zeros == 0) return n - i;
                zeros--;
            }
        }
        return 0;
    }
};