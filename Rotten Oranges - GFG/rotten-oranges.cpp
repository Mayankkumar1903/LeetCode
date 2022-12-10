//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  
public:
    int orangesRotting(vector<vector<int>>& grid) {

        //just normal bfs trasversal

        int n=grid.size();
        int m=grid[0].size();
        int visited[n][m];
        int cnt=0,cntfresh=0;
        queue<pair<pair<int,int>,int>> q;
        //it will store <row,col>,time
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                     visited[i][j]=2;
                }
                else 
                       visited[i][j]=0;
                if(grid[i][j]==1)
                cntfresh++;
            }
        }
        int time=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++){
                //now we will check for fresh oranges
                int nrow = r+delrow[i];
                int ncol= c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited  [nrow] [ncol]==0 && grid[nrow][ncol]==1 ){
                        q.push({{nrow,ncol},t+1});
                        visited[nrow][ncol]=2;
                        cnt++;
                }

            }
        }
       
        if(cnt!=cntfresh)return -1;
        return time;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends