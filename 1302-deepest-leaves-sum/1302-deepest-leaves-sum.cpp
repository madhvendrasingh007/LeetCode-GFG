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
    int deepestLeavesSum(TreeNode* root) {
        int max_height = findHeight(root);
        
        return deepestSum(root, max_height);
    }
    
    int findHeight(TreeNode* root) {
        if (root == nullptr) 
            return 0;    
        
        return 1+max(findHeight(root->left), findHeight(root->right));        
    }
    
    int deepestSum(TreeNode* root, int count) {
        if (root == nullptr) 
            return 0;
        
        count--;
        
        if (count == 0) 
            return root->val;    
        
        return deepestSum(root->right, count) + deepestSum(root->left, count);
    }

};