class Solution {
public:

    // returns {sum, count}
    pair<int, int> dfs(TreeNode* root, int& ans) {

        if (root == nullptr)
            return {0, 0};

        // Get information from left subtree
        auto left = dfs(root->left, ans);

        // Get information from right subtree
        auto right = dfs(root->right, ans);

        // Calculate current subtree
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        // Average of current subtree
        if (root->val == sum / count)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {

        int ans = 0;

        dfs(root, ans);

        return ans;
    }
};