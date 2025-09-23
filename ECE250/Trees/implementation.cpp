

// post-order uses a stack? Yes, post-order traversal can be implemented using a stack. In fact, both iterative and recursive approaches can be used to achieve post-order traversal. The stack helps keep track of the nodes to be processed, ensuring that the left and right children are visited before the parent node.
#include <iostream>
#include <stack>
class TreeNode
{
public:
    int value;

    // must be pointers to allow for dynamic memory allocation (otherwise infinite size)
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// same as dfs
void PreorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    // recursive approach
    std::cout << root->value << " "; // Process the node
    PreorderTraversal(root->left);   // TreeNode is a pointer, why?
    PreorderTraversal(root->right);
}

void PostOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    // recursive approach
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    std::cout << root->value << " "; // Process the node AT THE END
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);
    PreorderTraversal(root);
    std::cout << std::endl;

    return 0;
}

// binary search tree (BST) is a data structure that facilitates fast lookup, addition, and removal of items. Each node in a BST has at most two children, referred to as the left and right child. The left child's value is less than its parent's value, while the right child's value is greater than its parent's value. This property allows for efficient searching, as it narrows down the possible locations of a value with each comparison.

// O(logn) average time complexity for search, insertion, and deletion operations in a
// balanced BST. However, in the worst case (e.g., when the tree becomes unbalanced and resembles a linked list), these operations can degrade to O(n) time complexity.

// Example of a simple binary search tree implementation in C++

// foreach node, the left node is less than the current node, and the right node is greater than the current node
// always traverse

// this is just a tree tho
class BSTNode
{
public:
    int value;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

bool searchABST(TreeNode *root, int target)
{

    if (root == nullptr)
    {
        return false;
    }
    else if (root->value == target)
    {
        return true;
    }
    else if (root->value < target)
    {
        // go to the right cuz our target is bigger than the current node
        return searchABST(root->right, target);
    }
    else if (root->value > target)
    {
        // go to the left cuz our target is smaller than the current node
        return searchABST(root->left, target);
    }
}