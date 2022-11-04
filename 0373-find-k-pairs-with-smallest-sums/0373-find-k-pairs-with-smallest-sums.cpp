typedef pair<int,pair<int,int>> ppi;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        priority_queue<ppi, vector<ppi> , greater<ppi>> minh;
        
        for(int i=0; i<n1&&i<k; i++){
            minh.push({nums1[i]+nums2[0],{i,0}});
        }
        
        while(minh.size()>0 && k--){
            auto temp = minh.top();
            minh.pop();
            int i= temp.second.first;
            int j= temp.second.second;
            
            res.push_back({nums1[i],nums2[j]});
            
            if(j+1 <n2){
                minh.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }
        return res;
    }
};