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
    bool is_possible(int arr[], int n, int m,int mid){

        

        int page_sum=0;

        int student=1;

        for(int i=0;i<n;i++){

            

            if(page_sum+arr[i] <= mid){

                page_sum+=arr[i];

            }

            else{

                student++;

                if(arr[i] > mid || student > m){

                    return false;

                }

                page_sum=0;

                page_sum+=arr[i];

            }

        }

        return true;

    }

    

    int findPages(int arr[], int n, int m) 

    {

        //code here

        

        if(m > n){

            return -1;

        }

        int l=0;

        int u=0;

        

        for(int i=0;i<n;i++){

            u+=arr[i];

        }

        int ans=-1;

        int mid;

        while(l<=u){

             mid= l+(u-l)/2;

             

             if(is_possible(arr,n,m,mid)){

                 ans=mid;

                 u=mid-1;

             }

             else{

                 l=mid+1;

             }

        }

        return ans;

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