class Solution {
public:
    string addOne(string &s) {
        int i = s.size() - 1;
        while(i >= 0 and s[i] == '1') {
            s[i] = '0';
            i--;
        }
        if(i >= 0) {
            s[i] = '1';
        }else {
            s = "1" + s;
        }
        return s;
    }
    int numSteps(string s) {
        
        int operations = 0;
        
        while(s.size() > 1) {
            
            if(s.back() == '1') {
                //add one
                addOne(s);
            }else {
                //divide by two
                s.pop_back();
            }
            ++operations;
        }
        return operations;
    }
};