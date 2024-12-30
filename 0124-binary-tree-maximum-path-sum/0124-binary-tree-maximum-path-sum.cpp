class Solution {
public:
    int pathsum(TreeNode* root, int &maxi){
        if(root==NULL){
            return 0;
        }
        int left = max(0, pathsum(root->left,maxi));
        int right = max(0, pathsum(root->right,maxi));
        maxi = max (maxi, root->val+left+right);
        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi = INT_MIN;
        pathsum(root,maxi);
        return maxi;
    }
};