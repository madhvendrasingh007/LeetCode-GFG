class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
         multiset<int> climbs;
        int n = heights.size();
        
        for (int i = 1; i < n; i++) {
            
            if (heights[i] - heights[i-1] > 0) {
                climbs.insert(heights[i] - heights[i-1]);
            }
                
            if (climbs.size() > ladders) {
                bricks -= *climbs.begin();
                climbs.erase(climbs.begin());
                if (bricks < 0) return i-1;
            }
        }
        return n-1;
    }
};