// Moving onto parts c and d, I had to do a new program in order to get it to work so please
// use this code as a separate part to check these parts
#include <bits/stdc++.h>
using namespace std;

enum Color {RED, BLACK};

struct node
{
    int data;
    bool color;
    node *left, *right, *parent;
    node(int data)
    {
        this->data = data;
        left = right = parent = NULL;
    }
};
//We will create a red and black tree to demonstrate rotation
class RBTree
{
private:
    node *root;
protected:
    void rotateLeft(node *&, node *&);
    void rotateRight(node *&, node *&);
    void fixViolation(node *&, node *&);
public:
    // Constructor
    RBTree() { root = NULL; }
    void insert(const int &n);
    void inorder();
    void levelOrder();
};

void inorderHelper(node *root)
{
    if (root == NULL)
        return;
    inorderHelper(root->left);
    cout << root->data << "  ";
    inorderHelper(root->right);
}

node* BSTInsert(node* root, node *pt)
{
    if (root == NULL)
        return pt;
    if (pt->data < root->data)
    {
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }
    return root;
}


void levelOrderHelper(node *root)
{
    if (root == NULL)
        return;
    std::queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << "  ";
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

void RBTree::rotateLeft(node *&root, node *&pt)
{
    node *pt_right = pt->right;
    pt->right = pt_right->left;
    if (pt->right != NULL)
        pt->right->parent = pt;
    pt_right->parent = pt->parent;
    if (pt->parent == NULL)
        root = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;
    pt_right->left = pt;
    pt->parent = pt_right;
}

void RBTree::rotateRight(node *&root, node *&pt)
{
    node *pt_left = pt->left;
    pt->left = pt_left->right;
    if (pt->left != NULL)
        pt->left->parent = pt;
    pt_left->parent = pt->parent;
    if (pt->parent == NULL)
        root = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;
    pt_left->right = pt;
    pt->parent = pt_left;
}

// Error fixer
void RBTree::fixViolation(node *&root, node *&pt)
{
    node *parent_pt = NULL;
    node *grand_parent_pt = NULL;

    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED))
    {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;
        if (parent_pt == grand_parent_pt->left)
        {

            node *uncle_pt = grand_parent_pt->right;
            if (uncle_pt != NULL && uncle_pt->color == RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }

            else
            {
                if (pt == parent_pt->right)
                {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
        else
        {
            node *uncle_pt = grand_parent_pt->left;
            if ((uncle_pt != NULL) && (uncle_pt->color == RED))
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                if (pt == parent_pt->left)
                {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

void RBTree::insert(const int &data)
{
    node *pt = new node(data);

    // Do a normal BST insert
    root = BSTInsert(root, pt);

    // fix Red Black Tree violations
    fixViolation(root, pt);
}
void RBTree::inorder()     {  inorderHelper(root);}
void RBTree::levelOrder()  {  levelOrderHelper(root); }



void transformToList(node *root, node **head)
{
    if (root == NULL) return;
    static node* prev = NULL;
    transformToList(root->left, head);
    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    // Finally convert right subtree
    transformToList(root->right, head);
}

node* newNode(int data)
{
    node* new_node = new_node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

void printList(node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->right;
    }
}

//In order to test the second code portion use this int main.
int main()
{
    RBTree tree;

    tree.insert(2);
    tree.insert(7);
    tree.insert(5);
    tree.insert(9);
    tree.insert(6);
    tree.insert(4);

    cout << "In order Tree is:\n";
    tree.inorder();

    cout << "\n\nLevel Order Tree is:\n";
    tree.levelOrder();

    // random tree
    node *root        = newNode(11);
    root->left        = newNode(21);
    root->right       = newNode(35);
    root->left->left  = newNode(28);
    root->left->right = newNode(47);
    root->right->left = newNode(63);

    node *head = NULL;
    transformToList(root, &head);

    printList(head);

    return 0;
}

