// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        long count =0;
        int mi=0;  //  this is to find index which has maximum value in array.
        
        
        for(int i =1;i<n;i++)   
           if(arr[i]>arr[mi])
               mi=i;
       
        int mhl =0;   // initilly taking maximum height left =0
        int mhr=0;  // initilly taking maximum height right =0
       
       
       // now breaking the array in two part left ---> maximum index and maximum index <--- right.
        for(int i=0;i<mi;i++){
        
            if(arr[i]>mhl)    // here comparing if the current is higher than max height if yes then assigning it to mhl
                mhl =arr[i];
        else
            count+= mhl-arr[i]; // else adding maximum height left - current height
        }
        
    
        for(int i=n-1;i>mi;i--){
        
            if(arr[i]>mhr)
                mhr = arr[i];
            else
                count+= mhr-arr[i];
        
        
        }
        return count;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends