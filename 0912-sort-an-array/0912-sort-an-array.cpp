class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int> , greater<int>> minh;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            minh.push(nums[i]);
        }
        while(minh.size()>0){
            res.push_back(minh.top());
            minh.pop();
        }
        return res;
    }
};