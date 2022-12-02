class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return false;
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;
        set<char>s1;
        set<char>s2;
        vector<int>v1,v2;
    for(int i=0;i<word1.size();i++)
    {
        map1[word1[i]]++;
        map2[word2[i]]++;
    }
        for(auto it:map1){
            v1.push_back(it.second);
            s1.insert(it.first);
        }
        for(auto ig: map2){
            v2.push_back(ig.second);
            s2.insert(ig.first);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2&&s1==s2;
    }
};