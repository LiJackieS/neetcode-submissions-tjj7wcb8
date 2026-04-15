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
    int goodNodes(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode*, int>> queue;
        queue.push({root, INT_MIN});
        while (!queue.empty()) {
            auto [node, maxVal] = queue.front();
            queue.pop();
            if (node->val >= maxVal) {
                res++;
            }
            if (node->left) {
                queue.push({node->left, max(node->val, maxVal)});
            }
            if (node->right) {
                queue.push({node->right, max(node->val, maxVal)});
            }
        }
        return res;
    }
};
