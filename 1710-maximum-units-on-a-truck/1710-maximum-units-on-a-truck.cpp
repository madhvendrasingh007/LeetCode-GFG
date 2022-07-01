class Solution {
public:
    
    static bool comp(vector<int> &a,vector<int> &b){
        return a[1] >= b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int count = 0;
        for(int i = 0;i < boxTypes.size();i++){
            int temp = min(boxTypes[i][0],truckSize);
            int temp2 = temp * boxTypes[i][1];
            // cout << temp << " " << temp2 << endl;
            truckSize -= temp;
            count += temp2;
        }
        
        return count;
    }
};
