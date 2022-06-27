// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
  public:
    int findUnique(int a[], int n, int k) {
    int sum=0,res=0;
       for(int i=0;i<64;i++){
           sum=0;
           for(int j=0;j<n;j++){
               if(a[j] & (1<<i)){
                   sum++;
               }
           }
           if(sum%k!=0){
              res=(res|(1<<i)); 
           }
       }
       return res;
    }

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        cout << obj.findUnique(a, n, k) << endl;
    }
}  // } Driver Code Ends