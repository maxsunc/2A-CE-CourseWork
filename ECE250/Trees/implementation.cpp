

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

// insert a value into the BST
BSTNode *insertIntoBST(BSTNode *root, int val)
{
    if (root == nullptr)
    {
        return new BSTNode(val);
    }

    if (val < root->value)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else if (val > root->value)
    {
        root->right = insertIntoBST(root->right, val);
    }
    // if val == root->value, do nothing (no duplicates in this BST)

    return root;
}

BSTNode *findMin(BSTNode *node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

BSTNode *deleteNode(BSTNode *root, BSTNode *key)
{
    if (root == nullptr)
    {
        return root;
    }

    if (key->value < root->value)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key->value > root->value)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // // we are at the node to be deleted

        // check for no child
        if (root->left == nullptr && root->right == nullptr)
        {
            // delete it with no constraints
            delete root;
            root = nullptr;
            return root;
        }

        // check for both children active
        if (root->left != nullptr && root->right != nullptr)
        {
            // find the successor of this node
            BSTNode *successor = getSuccessor(root, key);
            // wtf why is thisso hard
        }

        // // Node with only one child or no child
        // if (root->left == nullptr) {
        //     BSTNode* temp = root->right;
        //     delete root;
        //     return temp;
        // } else if (root->right == nullptr) {
        //     BSTNode* temp = root->left;
        //     delete root;
        //     return temp;
        // }

        // // Node with two children: Get the inorder successor (smallest in the right subtree)
        // BSTNode* temp = findMin(root->right);

        // // Copy the inorder successor's content to this node
        // root->value = temp->value;

        // // Delete the inorder successor
        // root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

BSTNode *getSuccessor(BSTNode *root, BSTNode *node)
{
    // value that is one higher then us
    if (node->right != nullptr)
    {
        return findMin(node->right);
    }
    else
    {
        // there is nobody to the right of us
        // go up until we can find someone bigger
        BSTNode *successor = nullptr; // update until find best value
        BSTNode *current = root;

        while (current != nullptr)
        {

            if (current->value > node->value)
            {
                // update successor
                successor = current;
                // update current to look for another successor (how much lower can we go?)
                current = current->left;
            }
            else if (current->value < node->value)
            {
                // we went too low I think we're done
                // there could a version on the right that works
                current = current->right;
            }
            else
            {
                // we found our node
                break;
            }
        }
        return successor;
    }
}

// avl tree
class avlNode
{
public:
    int value;
    avlNode *left;
    avlNode *right;
    int height;

    avlNode(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};