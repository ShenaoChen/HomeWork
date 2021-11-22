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
    int ans = 0;

    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode * root){
        if(root == nullptr)
            return 0;
        int sum_left = dfs(root -> left);
        int sum_right = dfs(root -> right);
        ans += abs(sum_left - sum_right);
        return sum_left + sum_right + root->val;
    }
};
