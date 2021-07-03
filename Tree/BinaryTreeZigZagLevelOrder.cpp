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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Define a zag level to process a level from left to right and a zig level to be processed right              to left. Then, at a zag level at children to a stack from left to right, since we want the last            node of that layer to be the first one processed. Same logic applies to zig level where children            of nodes at a zig level will be added right to left since we want left most node of that layer              to be processed first.
        if (!root) return {};
        
        stack<TreeNode*> zig_s;
        stack<TreeNode*> zag_s;
        vector<vector<int>> ret;
        bool zig = false;
        
        zag_s.push(root);
        while (!zig_s.empty() || !zag_s.empty()) {
            vector<int> cur_lvl;
            int size = zig ? zig_s.size() : zag_s.size();
            
            for (int i = 0; i < size; i++) {
                auto& node = zig ? zig_s.top() : zag_s.top();
                cur_lvl.push_back(node->val);
                if (zig) {
                    zig_s.pop();
                    if (node->right) zag_s.push(node->right);
                    if (node->left) zag_s.push(node->left);
                } else {
                    zag_s.pop();
                    if (node->left) zig_s.push(node->left);
                    if (node->right) zig_s.push(node->right);
                }
            }
            
            // zig --> zag & zag -->zig
            zig ^= 1;
            ret.push_back(cur_lvl);
        }
        
        return ret;
    }
};
