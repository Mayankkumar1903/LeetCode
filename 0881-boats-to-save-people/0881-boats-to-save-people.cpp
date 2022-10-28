class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n= people.size();
        sort(people.begin(),people.end());
        
        int left=0;
        int right= n-1;
        int boat=0;
        while( left<=right){
            int totalwt= people[left]+ people[right];
            
            if(totalwt<= limit){
                boat++;
                left++;
                right--;
            }
            else{
                boat++;
                right--;
            }
        }
        return boat;
    }
};