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
vector<string>v;
    
    void solve(TreeNode* root,string s){
        if(!root){
            if(s!="")
            return;
            else
            v.push_back(s);
            return;
        }

        s=s+to_string(root->val)+"->";
        if(!root->left and !root->right){
            s=s.substr(0,s.size()-2);
            v.push_back(s);
        }
        if(root->left)
        solve(root->left,s);
        if(root->right)
        solve(root->right,s);
        
       
        
}

    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        solve(root,s);
        return v;
        
    }
};
