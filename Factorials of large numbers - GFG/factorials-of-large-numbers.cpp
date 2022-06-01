// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int>res;
        res.push_back(1);
        for(int j=2;j<=N;j++){
            int carr=0;
            for(int i=0;i<res.size();i++){
                int val=res[i]*j+carr;
                res[i]=val%10;
                carr=val/10;
            }
            while(carr!=0){
                res.push_back(carr%10);
                carr/=10;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends