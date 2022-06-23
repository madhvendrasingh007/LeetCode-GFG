class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);
        int n = courses.size();
        priority_queue<int>pq;
        int cnt = 0;
        for(auto x:courses){
            if(x[0]+cnt<=x[1]){
                pq.push(x[0]);
                cnt+=(x[0]);
            }else{
                if(!pq.empty() && pq.top()>x[0]){
                    cnt-=pq.top();
                    pq.pop();
                    pq.push(x[0]);
                    cnt+=x[0];
                }
            }
        }
        
        return pq.size();
    }
};