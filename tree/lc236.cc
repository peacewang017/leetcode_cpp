#include "../type/tree.h"

using namespace std;

class Solution {
public:
    TreeNode *ans;
    // 递归函数的意义是：以 root 为根的树中是否存在 p 或 q
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) {
            return false;
        }
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((lson || rson) && (root == p || root == q))) {
            ans = root;
        }
        return lson || rson || (root == p) || (root == q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};