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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* rightside = q.front();
            int size = q.size();
            for (int i = size; i > 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                if (node != nullptr) {
                    rightside = node;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (rightside != nullptr) {
                res.push_back(rightside->val);
            }
        }
        return res;
    }
};
