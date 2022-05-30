// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int top=0,bottom=n,left=0,right=m;
        
        while(top<=bottom && left<=right){
            
            //first row
            for(int i=left;i<right;i++){
                if(k==1)
                    return a[top][i];
                k--;
            }
            top++;
            
            //last col
            for(int i=top;i<bottom;i++){
                if(k==1)
                return a[i][right-1];
                k--;
            }
            right--;
            // last row
            if(left<right){
                for(int i=right-1;i>=left;i--){
                    if(k==1)
                    return a[bottom-1][i];
                    k--;
                }
           
            }
            bottom--;
            //first column
            if(top<bottom){
                for(int i=bottom-1;i>=top;i--){
                    if(k==1)
                    return a[i][left];
                    k--;
                }
                
            }
            left++;
        }
    }

};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}  // } Driver Code Ends