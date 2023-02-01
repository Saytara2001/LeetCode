class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int gcd = __gcd(str1.size(), str2.size());
        string tmp = "";
        for(int i = 0; i < gcd; i++)
            tmp += str1[i];
        
        for(int i = 0; i+gcd <= str1.size(); i += gcd)
            if(str1.substr(i, gcd) != tmp){
                cout<<str1.substr(i, gcd) <<" "<< tmp<<endl;
                return "";
            }
        
        for(int i = 0; i+gcd <= str2.size(); i += gcd)
            if(str2.substr(i, gcd) != tmp)
                return "";
        
        return tmp;
    }
};