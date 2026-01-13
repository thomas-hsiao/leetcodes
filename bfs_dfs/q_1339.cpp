/*
Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.

 

Example 1:

Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

Example 2:

Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

 

Constraints:

    The number of nodes in the tree is in the range [2, 5 * 10^4].
    1 <= Node.val <= 10^4


*/

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
private:
    long mod = 1'000'000'007;
    void dfs_total(TreeNode* root, long& total) {
        if (root == nullptr) return;

        total += root->val;
        dfs_total(root->left, total);
        dfs_total(root->right, total);
    }
    long dfs(TreeNode* root, long& total, long& max_prod) {
        if (root == nullptr) return 0;

        long left_sum = dfs(root->left, total, max_prod);
        long right_sum = dfs(root->right, total, max_prod);
        long sum = root->val + left_sum + right_sum;

        max_prod = std::max(max_prod, sum * (total - sum));
        
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        long max_prod = 0;
        long total = 0;
        dfs_total(root, total);        
        dfs(root, total, max_prod);

        return max_prod % mod;
    }
};