class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int arr[n];
        
        for(int i=0;i<n;i++)
        {
            int cur=0;
            
            for(int j=0;j<words[i].size();j++)
            {
                int nm = words[i][j]-'a';
                cur = cur | 1<<nm;
            }
            arr[i] = cur;
        }
        int res=0;
        for(int i=0;i<n;i++)
        
            for(int j=i+1;j<n;j++)
            
                
                if((arr[i]&arr[j])==0)
                {
                    int val = words[i].size()*words[j].size();
                    
                    res = max(res,val);
                }
            
        
        return res;
    }
};