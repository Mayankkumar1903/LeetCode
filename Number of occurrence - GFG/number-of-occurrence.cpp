//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int target) {
	    // code here
	    
        int start = 0;
        int end = n-1;
        int firstoccur = -1;
        int lastoccur =-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target) {
                firstoccur = mid;
                end = mid-1;
            }
            else if(nums[mid] < target )start = mid+1;
            else end = mid -1;

        }
        start =0;
        end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                lastoccur = mid;
                start = mid+1;
            }
            else if(nums[mid] < target) start = mid+1;
            else end = mid-1;
        }
        if(lastoccur!=-1 || firstoccur !=-1 )

        return lastoccur-firstoccur+1;

        else 

        return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends