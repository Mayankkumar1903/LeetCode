class Solution {
public:
    vector<string> res;
    
    void generator(string s,int openbra,int closebra){
        if(openbra==0  &&  closebra==0){
            res.push_back(s);
            return;
        }
        if(openbra>0)  generator(s+ "(",openbra-1,closebra);
        if(openbra<closebra) generator(s+")",openbra,closebra-1);
    }
    vector<string> generateParenthesis(int n) {
        generator("",n,n);
        return res;
    }
};