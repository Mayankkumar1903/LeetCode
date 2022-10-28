class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int ,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
           for(auto i:mp) {
            if(i.second > 1)
                return i.first;
        }
        return 0;
    }
};

// map<int, int> m;
//         int duplicate = 0;
//         for(auto i= 0; i<nums.size(); ++i)
//         ++m[nums[i]];
        
//         for(auto i : m)
//         {
//             if(i.second > 1)
//             {
//                 duplicate = i.first;
//                 break;
//             }
//         }
//         return duplicate;