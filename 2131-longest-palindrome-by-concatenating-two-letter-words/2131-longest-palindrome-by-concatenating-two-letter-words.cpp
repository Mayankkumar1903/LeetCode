class Solution {
public:
    int longestPalindrome(vector<string>& words) {
       int length=0;
        unordered_map<string, int> hm;
        for(string s: words){
            string check=s;
            reverse(check.begin(),check.end());
            if(hm[check] > 0){
                length+=4;
                hm[check]--;
            }
            else {
                hm[s]++;
            }
        }
        for(auto equal : hm){
            if(equal.first[0]==equal.first[1] && equal.second >0)
                return  length +=2;
        }
        
        return length;
    }
    
};