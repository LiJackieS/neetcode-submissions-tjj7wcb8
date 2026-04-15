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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<vector<int>> res;

        if (!root) {
            return res;
        }
        queue.push(root);

        while (!queue.empty()) {
            vector<int> temp;
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                auto cur = queue.front();
                queue.pop();
                temp.push_back(cur->val);
                if (cur->left) {
                    queue.push(cur->left);
                }
                if (cur->right) {
                    queue.push(cur->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
