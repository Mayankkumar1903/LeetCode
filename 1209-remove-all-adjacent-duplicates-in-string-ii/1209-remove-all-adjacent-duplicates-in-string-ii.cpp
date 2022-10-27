class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        st.push({'#', 0}); // just to reduce extra condition checks.
//     stack will keep char and its count;
        for(int i=0;i<s.size();i++){
            st.push({s[i],st.top().first==s[i]?st.top().second+1:1});
//         check if the char we are going to push is available in stack or not , if available don't push the char
//             increase the count by 1;
            if(st.top().second==k){
                while(st.top().first==s[i])
                    st.pop();
                    s.erase(i-k+1,k);
                    i=i-k;
                
            }
        }
        return s;
    }
};