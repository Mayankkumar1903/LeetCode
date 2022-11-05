class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxh;
        int sum=0;
        for(int i=0;i<piles.size();i++){
            maxh.push(piles[i]);
        }
        while(k>0){
            int x= maxh.top();
            maxh.pop();
            int y=floor(x/2);
            maxh.push(x-y);
            k--;
        }
       while(maxh.size() >0){
            sum+=maxh.top();
            maxh.pop();
        }
        return sum;
    }
};