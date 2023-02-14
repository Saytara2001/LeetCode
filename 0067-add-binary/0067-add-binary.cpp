class Solution {
public:
    string addBinary(string a, string b) {
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        if(a.size() > b.size()) swap(a, b);
        
        while(a.size() < b.size())
            a.push_back('0');
        
        a.push_back('0');
        b.push_back('0');
        
        int haveCarry = 0;
        string ans = "";
        for(int i = 0; i < a.size(); i++) {
            int ones = a[i] - '0' + b[i] - '0' + haveCarry;
            haveCarry = 0;
            if(ones == 0) ans.push_back('0');
            else if(ones == 1) ans.push_back('1');
            else if(ones == 2) ans.push_back('0'), haveCarry = 1;
            else if(ones == 3) ans.push_back('1'), haveCarry = 1;
        }
        while(ans.size() > 1 and ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};