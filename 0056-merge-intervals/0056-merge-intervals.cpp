class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        for(int i =0; i<n; i++){
            
            if(ans.empty()|| arr[i][0]>ans.back()[1]){
                //its the new one 
                ans.push_back(arr[i]);
            }
            //if its not this then
            else{
                ans.back()[1] = max(arr[i][1], ans.back()[1]);
            }
            
        }
        return ans;
    }
};