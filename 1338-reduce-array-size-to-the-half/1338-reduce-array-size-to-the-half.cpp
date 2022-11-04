class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        priority_queue<int> maxh;
        int res = 0, removed = 0;
        
        for (auto a : arr) mp[a]++;
        for (auto c : mp) maxh.push(c.second);
        
        while (removed < arr.size() / 2) {
            removed += maxh.top();
            maxh.pop();
            res++;
        }
        
        return res;
        
    }
};