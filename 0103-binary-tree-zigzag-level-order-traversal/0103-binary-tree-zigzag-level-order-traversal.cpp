/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight=1;
        while(!q.empty()){
            int size=q.size();
            vector<int> vec;
            for(int i=0;i<size;i++){
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                vec.push_back(q.front()->val);
                q.pop();
            }
            if(!leftToRight){
                reverse(vec.begin(),vec.end());
            }
            ans.push_back(vec);
            leftToRight=!leftToRight;
        }
        return ans;
    }
};