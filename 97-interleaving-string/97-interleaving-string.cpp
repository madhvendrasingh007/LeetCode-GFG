class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // BFS version
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (l1 + l2 != l3) return false;
        
        vector<vector<bool>> visited(l1 + 1, vector<bool>(l2 + 1, false));
        queue<pair<int, int>> myqueue;
        myqueue.push(pair<int, int>(0, 0));
        
        while(!myqueue.empty()) {
            auto p = myqueue.front();
            myqueue.pop();
            if (p.first == l1 && p.second == l2) {
                return true;
            }
            if (visited[p.first][p.second]) continue;
            if (p.first < l1 && s1[p.first] == s3[p.first + p.second]) {
                myqueue.push(pair<int, int>(p.first + 1, p.second));
            }
            if (p.second < l2 && s2[p.second] == s3[p.first + p.second]) {
                myqueue.push(pair<int, int>(p.first, p.second + 1));
            }
            visited[p.first][p.second] = true;
        }
        return false;
    }
};
