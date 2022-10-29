//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int start=0;
    int end = n-1;
    int res=-1;
    while(start<=end){
        int mid= start + (end - start)/2;
        if( x== arr[mid])
         {
             res=mid;
             start= mid+1;
         }
         else if( x> arr[mid]){
             start = mid+1;
             
         }
         else
          end = mid-1;
    }




// int res2=-1;
  start=0;
    end = n-1;
    int res2=-1;
    while(start<=end){
        int mid= start + (end - start)/2;
        if( x== arr[mid])
         {
             res2=mid;
             end= mid-1;
         }
         else if( x> arr[mid]){
             start = mid+1;
             
         }
         else
          end = mid-1;
    }

return {res2,res};
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends