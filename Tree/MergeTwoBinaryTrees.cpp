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
    TreeNode* helper(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        
        // Step 1
        TreeNode* new_left = nullptr;
        TreeNode* new_right = nullptr;
        if (root1 && root2) {                     // 1a
            root1->val = root1->val + root2->val; 
            new_left = helper(root1->left, root2->left);
            new_right = helper(root1->right, root2->right);       
        }
        else {                                    // 1b
            if (root1) {
                new_left = helper(root1->left, nullptr);
                new_right = helper(root1->right, nullptr);  
            } else {
                root1 = new TreeNode(root2->val);                
                new_left = helper(nullptr, root2->left);
                new_right = helper(nullptr, root2->right);       
            }
        }
        
        root1->left = new_left;
        root1->right = new_right;
        return root1;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // Method 1:
        //          Step 1: Check if root1 and root2 are valid
        //                1a: If both are, then set root1's new value to be the sum of both
        //                1b: If either is not, then set root1 to be the non-null node
        //          Step 2: Recurse on root1 and root2 left and right (regardless of if they're valid)
        //          Step 3: Repeat these steps until both are root1 and root2 are null
        return helper(root1, root2);
    }
};
