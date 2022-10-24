class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int goodpairs=0;
        unordered_map<int,int> m;
//         now lets chck each element is present in map or not 
//         add their previous value to goodpairs
        for(int i=0;i<nums.size();i++){
            goodpairs+=m[nums[i]]++;
        }
        return goodpairs;
    }
};