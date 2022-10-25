class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char ,int> mp;
//         it will store the char and their last occuring index;
//         now we will put all the char into the map;
        
    for (int i=0;i<s.size();i++){
        char ch=s[i];
        mp[ch]=i;
    }
        
        vector<int> res;
        int prev=-1;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            maxi=max(maxi,mp[s[i]]);
            if(maxi==i){
            res.push_back(maxi-prev);
            prev=maxi;
        }
            
        }
        return res;
    }
};