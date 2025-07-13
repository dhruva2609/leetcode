
class Solution {
public:
    int getLeftHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    int getRightHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        if (leftHeight == rightHeight) {
            // Perfect binary tree
            return (1 << leftHeight) - 1;
        } else {
            // Not perfect, recurse on subtrees
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
