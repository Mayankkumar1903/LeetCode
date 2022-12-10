//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	int n;
	void dfs(vector<int>& vis, vector<vector<int>>& adj, int node) {
		vis[node] = 1;
		for (int i = 0; i < n; i++) {
			if (adj[node][i] == 1 and vis[i] == -1) {
				dfs(vis, adj, i);
			}
		}
	}
	int numProvinces(vector<vector<int>> adj, int V) {
		n = adj.size();
		vector<int> vis(n, -1);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (vis[i] == -1) {
				++ans;
				dfs(vis, adj, i);
			}
		}
    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends