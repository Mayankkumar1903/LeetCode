//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int k) 
    {
        //code here
        int start =0;
        int end = 0;
        for(int i=0;i<n;i++){
            end += arr[i];
        }
        
        int res=-1;
        if(k>n)
        return -1;
        
        while( start <= end){
            int mid= start + (end - start)/2;
            if(possible_to_give(arr, n, k, mid))
            {
                res = mid;
                end = mid-1;
            }
            else 
              {
                  start = mid+1;
              }
        }
        return res;
    }
    
    bool possible_to_give(int arr[],int n,int k,int mid){
        int page_sum=0;
        int student=1;
        for(int i=0;i<n;i++){
            if(page_sum + arr[i]<= mid)
               page_sum +=arr[i];
               
             else {
                 student++;
                 if(arr[i]>mid || student > k){
                     return false;
                 }
                 
                 page_sum=0;
                 page_sum+=arr[i];
             }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends