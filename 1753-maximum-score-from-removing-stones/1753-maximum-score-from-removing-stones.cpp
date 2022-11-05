class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> maxh;
        int count =0;
        maxh.push(a);
        maxh.push(b);
        maxh.push(c);
        while(maxh.size()  >= 2){
            int x= maxh.top();
            maxh.pop();
            int y= maxh.top();
            maxh.pop();
            if(x>0 && y>0){
            count++;
            maxh.push(x-1);
            maxh.push(y-1);}
        }
        return count;
    }
};