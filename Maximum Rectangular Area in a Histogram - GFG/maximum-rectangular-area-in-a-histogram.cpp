//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    
    /* this function will return a vector of all the min elements on left of each elment of the input array */
    
    vector<long long> prevSmallerEleVec(long long arr[], int size){
        
        vector<long long> ans(size);  //for storing result 
        stack<long long> stk;   // for finding right (next) min Ele
        stk.push(-1);  //initially 
        
        
        for(int i = 0; i < size; i++){
            
            long long curr = arr[i];
            
            //searching for lesser top than the arr[i]
            //poping elements from stack untill we find a element lesser than the arr[i]
            
            /* note : we want smaller ele's index , not value here */
           
            while((stk.top() != -1) && arr[stk.top()] >= curr){
                stk.pop();
            }
            
            //when lesser element found then push it's index in the ans vector and push the curr's index into the stack
            ans[i] = stk.top();
            stk.push(i);
            
        }
        
        return ans;
    }
    
    /* this function will return a vector of all the min elements on right of each elment of the input array */
    
    vector<long long> nextSmallerEleVec(long long arr[], int size){
    
        
        vector<long long> ans(size);  //for storing result 
        stack<long long> stk;   // for finding right (next) min Ele
        stk.push(-1);  //initially 
        
        for(int i = size-1; i >= 0; i--){
            
            long long curr = arr[i];
            
            //searching for lesser top than the arr[i]
            //poping elements from stack untill we find a element lesser than the arr[i]
            
            /* note : we want smaller ele's index , not value here */
           
            while((stk.top() != -1) && arr[stk.top()] >= curr){
                stk.pop();
            }
            
    //when lesser element found then push it's index in the ans vector and push the curr's index into the stack
            ans[i] = stk.top();
            stk.push(i);
            
        };
        
        return ans;
    }
    
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heightsVector[], int n)
    {
        int vecSize = n;
        
        long long maxArea = INT_MIN;   // this will keep on updated till we find the max area of histogram
        
        // step - 1 : finding next & prv smaller heights corresponding to each of ele of array (input)
        vector<long long> prvSmallVec = prevSmallerEleVec(heightsVector, vecSize);
        vector<long long> nxtSmallVec = nextSmallerEleVec(heightsVector, vecSize);
        
        // step - 2 : traverse whole vector of heights  
        // LSMI - Left smaller height index , RSM - Right smaller heights index
        for(int i = 0; i < vecSize; i++){
            
            // finding right smaller and left smaller heights index's for each arr[i]
            long long LSHIndex = prvSmallVec[i];
            long long RSHIndex;
            
            // when the right smaller ele index is -1 that means no smaller ele is their for some value of x , therefore we need to set index as n
            if(nxtSmallVec[i] == -1){
                RSHIndex = vecSize;
            }
            else{
                RSHIndex = nxtSmallVec[i];
            }
            
            // step - 3 : calculate the height, width from above both index's
            long long width = (RSHIndex - LSHIndex - 1);
            long long height = heightsVector[i];
            
            //step - 4 : calculate the area ,and if its the max area calculated till now then, update the maxArea 
            long long newArea = width * height;
            
            //updating the max area , whever required
            if(newArea > maxArea) maxArea = newArea;
            
        }
        
        // at last return the maxArea found in whole process
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends