class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* left_inverted = invertTree(root->left);
        TreeNode* right_inverted = invertTree(root->right);

        root->left = right_inverted;
        root->right = left_inverted;

        return root;
    }
};
