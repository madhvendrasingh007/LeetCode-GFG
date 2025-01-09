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
    int countNodes(TreeNode* root) {
        int left=0,right=0;
        TreeNode* curr=root;
        while(curr!=NULL){
            left++;
            curr=curr->left;
        }
        curr=root;
        while(curr!=NULL){
            right++;
            curr=curr->right;
        }
        if(left==right)
            return pow(2,left)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};