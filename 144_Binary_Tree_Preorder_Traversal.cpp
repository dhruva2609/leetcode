class Solution {
public:
    void helper(TreeNode* node, vector<int>& result) {
        if (!node) return;
        result.push_back(node->val);
        helper(node->left, result);
        helper(node->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
};
