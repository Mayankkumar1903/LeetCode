//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int i,int j1,int j2, int n, int m, vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=m ||j2>=m)return -1e9;// if robots goes out of bound 
        if(i==n-1){//if it reaches last row
            if(j1==j2)//if both reach at same place in last row
                return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] !=-1)return dp[i][j1][j2];
        int maxi = INT_MIN;
        //for one movement of robo1 there is 3 movement possible for robo 2 so there is 9 combo possible 
        for(int di=-1;di<=+1;di++){
            for(int dj=-1;dj<=1;dj++){
                int ans = 0;
                if(j1==j2)ans = grid[i][j1];
                else ans = grid[i][j1] + grid[i][j2];
                ans += solve(i+1,j1+di,j2+dj,n,m,grid,dp);
                maxi = max(ans,maxi);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // we have to declare 3d DP bcz we have to store [row][col][col]
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,n,m,grid,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends