#define ll long long

class Solution {
public:

    vector<ll> nums;
    ll TOTALSUM;

    bool isPossible(int nop, ll n)
    {
        ll totalSum = TOTALSUM;

        int reqPatch = 0;
        ll range = 0;
        int i = 0;

        while(i<nums.size())
        {
            if(nums[i]<=(range+1))
            {
                range = range + nums[i];
                i++;
            }
            else
            {
                while(nums[i]>(range+1))
                {
                    reqPatch++;
                    totalSum = totalSum + range + 1;
                    range = range + range + 1;
                }
            }
        }

        while(range<n)
        {
            reqPatch++;
            totalSum = totalSum + range + 1;
            range = range + range + 1;
        }

        if(totalSum<n)
        {
            reqPatch++;
        }

        if(reqPatch<=nop)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    int minPatches(vector<int>& N, int n) {
        bool flag = false;

        //if one is not present include 1
        if(N[0]!=1)
        {
            nums.push_back(1);
            TOTALSUM+=1;
            flag = true;
        }

        //if n==1 then special case
        if(n==1)
        {
            if(flag==true)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        //exclude all those numbers which are greater than n
        for(int i=0;i<N.size();i++)
        {
            if(N[i]<n)
            {
                nums.push_back(N[i]);
                TOTALSUM+=N[i];
            }
        }

        //initialize the binary search
        int high = n;
        int low = 0;

        int ans = high;

        //carry out binary search
        while(low<=high)
        {
            int mid = (high+low)/2;
            if(isPossible(mid, n))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        if(flag==true)
        {
            ans++;
        }

        return ans;
    }
};