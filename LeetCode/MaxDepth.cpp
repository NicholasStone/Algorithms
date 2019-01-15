//
// Created by Nicho on 2018/11/29 0029.
//
#include <queue>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth_recursive(TreeNode *root) {
    if (!root) return 0;// 没有节点
    if (root->left == root->right) return 1; // 叶子节点
    return (maxDepth_recursive(root->left) > maxDepth_recursive(root->right) ?
            maxDepth_recursive(root->left) :
            maxDepth_recursive(root->right))
           + 1;
}

void latestNodeOfLayer(TreeNode **node) {
    if ((*node)->right) *node = (*node)->right;
    else if ((*node)->left) *node = (*node)->left;
}

int maxDepth_no_recursive(TreeNode *root) {
    if (!root) return 0;// 没有节点
    if (root->left == root->right) return 1; // 孤家寡人

    TreeNode *node = root, *latest_of_layer;
    latestNodeOfLayer(&latest_of_layer);
    int depth = 1;

    queue<TreeNode *> layer;
    layer.push(node);

    while (!layer.empty()) {
        node = layer.front();
        layer.pop();

        if (node == latest_of_layer) {
            depth++;
            latestNodeOfLayer(&latest_of_layer);
        }

        if (node->left) {
            layer.push(node->left);
        }
        if (node->right) {
            layer.push(node->right);
        }
    }

    return latest_of_layer == node ? depth : depth + 1;
}

