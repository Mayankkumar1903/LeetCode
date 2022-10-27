class Solution {
public:
    string simplifyPath(string s) {
         int n = s.length();
        stack<string> st;
        for(int i=0; i<n; i++){
            if(s[i]=='/') continue;
            string tmp = "";
            while(i<n && s[i]!='/') tmp+=s[i++];
            if(tmp==".") continue;
            if(tmp==".."){
                if(!st.empty()) st.pop();
                continue;
            }
            else st.push(tmp);
        }
        
        string p = "";
        
        while(!st.empty()){
            p ="/"+st.top()+p;
            st.pop();
        }
        if(p=="")return"/";
        return p;
    }
};