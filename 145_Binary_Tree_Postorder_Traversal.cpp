class Solution {
public:
    void postorder(TreeNode* root, vector<int>& result) {
        if (!root) return;                 // Base case
        postorder(root->left, result);     // Traverse left subtree
        postorder(root->right, result);    // Traverse right subtree
        result.push_back(root->val);       // Visit current node
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};

