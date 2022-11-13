class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string res;
        for(int i=0;i<s.length();i++){
            res="";
           if(s[i]==' ')
               continue;
             while(s[i]!=' ' and i<s.length()){
              res+=s[i];
                i++;
            }
            st.push(res);
        }
        string res2="";
        while(!st.empty()){
            res2+=st.top();
            st.pop();
            if(!st.empty())
                res2+=" ";
            
        }
        return res2;
    }
};

