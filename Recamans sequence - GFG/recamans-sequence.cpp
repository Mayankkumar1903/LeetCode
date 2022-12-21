//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<int> recamanSequence(int n,vector<int> &res){
        if(n==0){
            res.push_back(0);
            return res;
        }
        recamanSequence(n-1,res);
        if(res[n-1]-n>0 and find(res.begin(),res.end(),res[n-1]-n)==res.end()){
            res.push_back(res[n-1]-n);
        }
        else{
            res.push_back(res[n-1]+n);
        }
        return res;
    }
    vector<int> recamanSequence(int n){
        // code here
        vector<int> res;
        return recamanSequence(n,res);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends