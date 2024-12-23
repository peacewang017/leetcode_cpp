#ifndef HEADER_TREE
#define HEADER_TREE

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {
    }
};

#endif