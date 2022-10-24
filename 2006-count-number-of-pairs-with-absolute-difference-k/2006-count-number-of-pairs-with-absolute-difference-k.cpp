class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
        int ans=0;
        for(auto it:nums){
            int val1=mp[it+k];
            int val2=mp[it-k];
            ans+=val1+val2;
            mp[it]++;
        }
        return ans;
    }
};