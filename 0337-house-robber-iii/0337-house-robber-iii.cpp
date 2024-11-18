class Solution {
    int doingRobbery(TreeNode *curr, unordered_map<TreeNode *, int> &ump){
        if(curr == nullptr) return 0;
        if(ump.find(curr) != ump.end()) return ump[curr];

        // Rob the current node
        int robbed = curr->val + 
                     ((curr->left) ? (doingRobbery(curr->left->left, ump) + doingRobbery(curr->left->right, ump)) : 0) + 
                     ((curr->right) ? (doingRobbery(curr->right->left, ump) + doingRobbery(curr->right->right, ump)) : 0);

        // Do not rob the current node
        int notRobbed = doingRobbery(curr->left, ump) + doingRobbery(curr->right, ump);

        // Store the result in the map and return the maximum of both scenarios
        return ump[curr] = max(robbed, notRobbed);
    }

public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, int> ump;
        return doingRobbery(root, ump);
    }
};