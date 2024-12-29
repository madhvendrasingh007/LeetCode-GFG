class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(root==NULL)return {};
        vector<int>res;
        stack<TreeNode*>st;
        st.push(root);
        while (st.empty()==false) {
            TreeNode*curr=st.top();
            st.pop();
            res.push_back(curr->val);
            // Note : order of if statements matter here 
            // first right then left means ,
            //in stack first go left then go right
            //which is preorder
            if(curr->right)st.push(curr->right);
            if(curr->left)st.push(curr->left);
        }
        return res;
    }
};