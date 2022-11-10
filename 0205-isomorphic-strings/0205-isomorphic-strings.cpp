class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>ch,mp;
        for(int i=0;i<s.size();i++){
            if(ch[s[i]]){
                if(ch[s[i]]!=t[i])
                    return false;
            }
              if(mp[t[i]]){
                if(mp[t[i]]!=s[i])
                    return false;
            }
            ch[s[i]]=t[i];
            mp[t[i]]=s[i];

        }
        return true;
    }
};