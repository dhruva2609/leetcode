class Solution {
public:
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> result;
        if (!root) {
            return result;
        }

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            double sum = 0.0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(sum / levelSize);
        }
        return result;
    }
};
