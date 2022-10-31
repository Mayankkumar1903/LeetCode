class Solution {
public:
    int findMin(vector<int>& nums) {
         //here we do binary search but in worst case it is O(n) (when all elements are same)
        
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            
            //compare mid element to find in which direction we have to move to find the min element
            if(nums[mid]<nums[high]){  //means min element lies in the left part
                high=mid;   
            }
            
            else if(nums[mid]>nums[high]){  //means min element lies in right part
                low=mid+1;
            }
            
            else{  //when element at mid and element at high are equal
                high--;
            }
            
        }
        return nums[low];
    }
};

 