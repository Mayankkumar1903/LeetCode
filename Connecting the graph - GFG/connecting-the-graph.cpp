//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
   
    public:
     vector<int> parent,size;
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1,n);
            for(int i=0;i<=n;i++)
              parent[i]=i;
        }
     
     
     int findUpar(int node){
         if(node==parent[node])
           return node;
         return parent[node]= findUpar(parent[node]);
     }
     
     void unionBysize(int u,int v){
         int ulp_u=findUpar(u);
         int ulp_v=findUpar(v);
         if(ulp_u == ulp_v)return ;
         if(size[ulp_u]<size[ulp_v]){
             parent[ulp_u] = ulp_v;
             size[ulp_v]+=size[ulp_u];
         }
         else{
             parent[ulp_v]=ulp_u;
             size[ulp_u]+=size[ulp_v];
         }
     }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet ds(n);  
        int extraedge = 0;
        for(auto it: edge){
            int u=it[0];
            int v=it[1];
            if(ds.findUpar(u)== ds.findUpar(v)){
                extraedge++;
            }
            else{
                ds.unionBysize(u,v);
            }
        }
        int connectedcomponent=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)
              connectedcomponent++;
        }
        
        int ans= connectedcomponent -1;
        if(extraedge >= ans) return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends