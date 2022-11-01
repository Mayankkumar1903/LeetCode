class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int start = 1;
        int end = *max_element(nums.begin(),nums.end());
        
        while(start < end){
            int mid = start + (end - start)/2;
            if(is_possible(nums,mid, threshold)){
                end = mid;
            }
            else 
                start = mid+1;
        }
        return start;
    }
    
    
    bool is_possible(vector <int>& nums, int mid, int threshold){
        int sum =0;
        for (int i=0;i< nums.size();i++){
            sum+=nums[i]/mid;
            if(nums[i]%mid !=0)
                sum++;
        }
        if(sum<= threshold)
        {
            sum=0;
            return true;
        }
        else
        {
            sum=0;
        }
        return false;
    }
};