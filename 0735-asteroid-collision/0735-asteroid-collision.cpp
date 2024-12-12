class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st; //as we have to check with the last that whether collision is there or not (LIFO)
        int n=asteroids.size();
        for(int i=0;i<n;i++)
        {
            if(asteroids[i]>0) //if +ve then directly into stack
                st.push(asteroids[i]);
            else
            {
                while(!st.empty() && st.top()<abs(asteroids[i]) && st.top()>0) //this only works when stack has element and they collide with current opposite direction asteroids
                    st.pop(); //destroying smaller value
                if(!st.empty() && st.top()==abs(asteroids[i]))
                    st.pop(); //destroy both
                else if(st.empty() || st.top()<0) //this condition is when no collision is possible
                    st.push(asteroids[i]);
            }
        }
        vector<int>ans; //to return in order
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};