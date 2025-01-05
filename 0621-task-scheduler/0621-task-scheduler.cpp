class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        unordered_map<char,int> mp;

        for(auto it : tasks) {
            mp[it]++;
        }


        priority_queue<int> maxHeap;

        for(auto it : mp) {
            maxHeap.push(it.second);
        }

        //Queue to store the value: {Time_To_Live,Time_At_Which_toBe_Invoked}
        queue<pair<int,int>> q;

        int time = 0;

        while(!maxHeap.empty() || !q.empty()) {
            time++;

            if(maxHeap.size() > 0) {
                int curr = maxHeap.top();
                maxHeap.pop();

                int count = curr-1;

                if(count > 0) {
                    q.push({count,time+n});
                }
            }

            if(!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};