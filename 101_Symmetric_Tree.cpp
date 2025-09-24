class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q || p->val != q->val) {
            return false;
        }
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }
};
