class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>>arr;
        int n=code.size();
        for(int i=0;i<n;i++){
            bool valid=true;
            for(int j=0;j<code[i].length();j++){
                if(!(isalnum(code[i][j]) || code[i][j]=='_')){
                    valid=false;
                    break;
                }
            }
            if(code[i].length()==0) valid=false;
            if(valid && isActive[i]){
                if(businessLine[i]=="restaurant" || businessLine[i]=="electronics" || businessLine[i]=="grocery" || businessLine[i]=="pharmacy" ) arr.push_back({businessLine[i],code[i]});
            }
        }
        unordered_map<string,int>mpp={
            {"electronics",0},
            {"grocery",1},
            {"pharmacy",2},
            {"restaurant",3}
        };
        sort(arr.begin(),arr.end(),[&](const pair<string,string>&a,const pair<string,string>&b){
            if(mpp[a.first]!=mpp[b.first]) return mpp[a.first]<mpp[b.first];
            return a.second<b.second;
        });
        vector<string>ans;
        for(int i=0;i<arr.size();i++) ans.push_back(arr[i].second);
        return ans;
    }
};