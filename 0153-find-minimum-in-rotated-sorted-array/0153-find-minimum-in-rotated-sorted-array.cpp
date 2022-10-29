class Solution {
public:
    int findMin(vector<int>& nums) {
         // int postoreturn = -1;
        int n= nums.size();
        int start = 0;
        int end = n-1;
        // int minEle;
        
//          we will find the minELement present in the array 
        // because the array prev to minELe is sorted from 0 to minELe -1   and the array after the minEle is sorted too;
        if(n==1) return nums[0];
        
        if(nums[0] < nums[n-1]) return nums[0];
        
        while( start <= end){
            int mid = start + (end - start)/2;
            
            int next = ( mid +1 )% n;
            int prev = ( mid + n-1) % n;
            
            if( nums[mid] < nums[prev] && nums[mid]<nums[next]){
                return nums[mid];
            }
           
            else if( nums[mid]> nums[ end]){
                start = mid+1;
            }
            else end= mid-1;
        }
      return -1;
    }
};