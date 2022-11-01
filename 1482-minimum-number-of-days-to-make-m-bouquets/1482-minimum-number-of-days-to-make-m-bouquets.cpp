class Solution {
public:
    
    
    
int minDays(vector<int>& bloomDay, int no_of_booke_banana, int no_of_fool_req) {
        
         int n= bloomDay.size();
    
        //base case
        if((long)no_of_booke_banana * no_of_fool_req > n) return -1; //impossible to make booke
        
        //As the no. of days should lie between range of min and max element
        
        int lower = *min_element(bloomDay.begin(), bloomDay.end());
        int upper = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(lower < upper){
            int mid = lower + (upper - lower)/2;
            
            if(check_if_possible_to_make(mid ,bloomDay,no_of_booke_banana, no_of_fool_req))
                upper = mid;
            else 
                lower = mid+1;
        }
        return lower;
    }
    
    
    
    
    //now lets see to our function 
     bool check_if_possible_to_make(int present_day, vector<int>& bloomDay , int no_of_booke_banana , int no_of_fool_req){
        int n= bloomDay.size();
         int flower_count =0;
         int booke_count =0;
         
         for(int i=0;i<n;i++){
             if(bloomDay[i] <= present_day){  // present_day ie.mid
                 flower_count++;
                 if(flower_count == no_of_fool_req){
                     booke_count++;
                     flower_count=0;
                 }
             }
             else {
                 flower_count =0;
             }
         }
         if(booke_count >= no_of_booke_banana)
             return true;
         else
             return false;
     }
};