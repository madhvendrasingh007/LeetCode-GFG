class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       int n = arr.size(),mod = 1e9+7;
       stack<pair<int,int>> st;
       vector<int> left(n,-1),right(n,-1);
       long long ans = 0;
       

       for(int i = 0;i<n;i++)
       {
          while(st.size()>0 && st.top().first>arr[i])
          st.pop();

          if(st.size()>0)
          left[i] = i-st.top().second;

          st.push({arr[i],i});
       }

       while(!st.empty())
       st.pop();


       for(int i = 0;i<n;i++)
       {
           while(st.size()>0 && st.top().first>arr[i])
           {
               right[st.top().second] = i-st.top().second;
               st.pop(); 
           }

           st.push({arr[i],i});
       }

       for(int i = 0;i<n;i++)
       {
           if(left[i]==-1)
           left[i] = i+1;

           if(right[i]==-1)
           right[i] = n-i;
           long long tmp = (left[i]*right[i])%mod;
           tmp = (tmp*arr[i])%mod;
           ans = (ans+tmp)%mod;
       }

       return ans;
    }
};