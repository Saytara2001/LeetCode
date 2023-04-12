class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        for(int i = 0; i < path.size(); i++) {
            
            if(path[i] == '/')
                continue;
            
            string t = "";
            while(i < path.size() and path[i] != '/') {
                t += path[i++];
            }
            
            if(t == ".")
                continue;
            else if(t == "..") {
                
                if(!st.empty())
                    st.pop();
            }else
                st.push(t);
            
        }
        string res = "";
        if(st.empty())
            res = "/";
        while(!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        return res;
    }
};