class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp {{'I',1},{'V',5},{'X',10},
                      {'L',50},{'C',100},{'D',500},{'M',1000}};
        long long sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X') && i+1 < s.size()){
                sum += mp[s[i+1]] - mp[s[i]];
                i++;
            }else if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C') && i+1 < s.size()){
                sum += mp[s[i+1]] - mp[s[i]];
                i++;
            }else if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M') && i+1 < s.size()){
                sum += mp[s[i+1]] - mp[s[i]];
                i++;
            }else{
                sum += mp[s[i]];
            }
        }
        return sum;
    }
};