class Solution {
public:
    int maxArea(vector<int>& height) {
        //we are using two pointer approach 
        int left = 0;
        int right = height.size() - 1;
        int maxi = 0;
        while(left < right){
            int w = right - left; //width of the container
            int h = min(height[left], height[right]);  //min height because the water will spill out from one side
            int area = h * w;
            maxi = max(maxi, area);
            if(height[left] < height[right]) left++;
            else if(height[left] > height[right]) right--;
            else {
                left++;
                right--;
            }
        }
        return maxi;
    }
};