
#include<stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h>

struct node
{
    int key;
    struct node *left, *right;
};

// This will just allow new nodes to be created
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// put function for insertion
struct node* put(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = put(node->left, key);
    else if (key > node->key)
        node->right = put(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}


// Thjs will search for a given key in a given BST
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

//The next portion of code implements sorting

void storeNodes(node* root, std::vector<node*> &nodes)
{
    // This will begin sorting nodes starting from the base case
    if (root==NULL)
        return;

    storeNodes(root->left, nodes);
    nodes.push_back(root);
    storeNodes(root->right, nodes);
}

// Recursive function is used here in oder to construct a binary tree
node* balanceTreeOne(std::vector<node*> &nodes, int start,
                    int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end)/2;
    node *root = nodes[mid];
    root->left  = balanceTreeOne(nodes, start, mid-1);
    root->right = balanceTreeOne(nodes, mid+1, end);

    return root;
}

//Now this will make it balanced
node* buildTree(node* root)
{
    std::vector<node *> nodes;
    storeNodes(root, nodes);
    int n = nodes.size();
    return balanceTreeOne(nodes, 0, n-1);
}



void sortedTree(int arr[], int start, int end)
{
    if(start > end)
        return;
    sortedTree(arr, start*2 + 1, end);
    printf("%d  ", arr[start]);
    sortedTree(arr, start*2 + 2, end);
}






// Driver Program to test above functions
int main()
{

    struct node *root = NULL;
    root = put(root, 5);
    put(root, 11);
    put(root, 14);
    put(root, 18);
    put(root, 20);


    // print BST before the sorting
    inorder(root);



    //print after BST sorting
    int arr[] = {5, 11, 14, 18, 20};
    int arr_size = sizeof(arr)/sizeof(int);
    sortedTree(arr, 0, arr_size-1);
    getchar();
    return 0;
}
// That concludes parts a and b