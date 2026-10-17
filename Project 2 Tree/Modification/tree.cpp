
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    bool lthread, rthread;
};

Node* createNode(int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    temp->lthread = true;
    temp->rthread = true;
    return temp;
}

Node* insert(Node* root, int value)
{
    Node* ptr = root;
    Node* parent = NULL;

    while (ptr != NULL)
    {
        if (value == ptr->data)
        {
            cout << "Duplicate value not allowed.\n";
            return root;
        }

        parent = ptr;

        if (value < ptr->data)
        {
            if (!ptr->lthread)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (!ptr->rthread)
                ptr = ptr->right;
            else
                break;
        }
    }

    Node* temp = createNode(value);

    if (parent == NULL)
        root = temp;
    else if (value < parent->data)
    {
        temp->left = parent->left;
        temp->right = parent;
        parent->left = temp;
        parent->lthread = false;
    }
    else
    {
        temp->right = parent->right;
        temp->left = parent;
        parent->right = temp;
        parent->rthread = false;
    }

    return root;
}

Node* leftmost(Node* ptr)
{
    if (ptr == NULL)
        return NULL;

    while (!ptr->lthread)
        ptr = ptr->left;

    return ptr;
}

Node* rightmost(Node* ptr)
{
    if (ptr == NULL)
        return NULL;

    while (!ptr->rthread)
        ptr = ptr->right;

    return ptr;
}

Node* predecessor(Node* ptr)
{
    if (ptr == NULL)
        return NULL;

    if (ptr->lthread)
        return ptr->left;

    return rightmost(ptr->left);
}

Node* successor(Node* ptr)
{
    if (ptr == NULL)
        return NULL;

    if (ptr->rthread)
        return ptr->right;

    return leftmost(ptr->right);
}

int countNodes(Node* root)
{
    int count = 0;
    Node* ptr = leftmost(root);

    while (ptr != NULL)
    {
        count++;
        ptr = successor(ptr);
    }

    return count;
}

int countNullPointers(Node* root)
{
    int count = 0;
    Node* ptr = leftmost(root);

    while (ptr != NULL)
    {
        if (ptr->left == NULL)
            count++;

        if (ptr->right == NULL)
            count++;

        ptr = successor(ptr);
    }

    return count;
}

void display(Node* root)
{
    Node* ptr = leftmost(root);

    cout << "\nTHREADED BST POINTER REPRESENTATION\n";

    while (ptr != NULL)
    {
        cout << "\nNode: " << ptr->data;

        cout << "\nLeft Pointer: ";
        if (ptr->lthread)
            cout << "Thread -> ";
        else
            cout << "Child Link -> ";

        if (ptr->left != NULL)
            cout << ptr->left->data;
        else
            cout << "NULL";

        cout << "\nRight Pointer: ";
        if (ptr->rthread)
            cout << "Thread -> ";
        else
            cout << "Child Link -> ";

        if (ptr->right != NULL)
            cout << ptr->right->data;
        else
            cout << "NULL";

        Node* pred = predecessor(ptr);
        Node* succ = successor(ptr);

        cout << "\nInorder Predecessor: ";
        if (pred != NULL)
            cout << pred->data;
        else
            cout << "None";

        cout << "\nInorder Successor: ";
        if (succ != NULL)
            cout << succ->data;
        else
            cout << "None";

        cout << "\n";
        ptr = successor(ptr);
    }
}

void inorder(Node* root)
{
    Node* ptr = leftmost(root);

    cout << "\nInorder Traversal: ";

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = successor(ptr);
    }

    cout << "\n";
}

int main()
{
    Node* root = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of nodes must be positive.\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        root = insert(root, value);
    }

    inorder(root);
    display(root);

    int nodes = countNodes(root);
    int before = nodes + 1;
    int after = countNullPointers(root);

    cout << "\nNULL POINTER COMPARISON\n";
    cout << "Total nodes: " << nodes;
    cout << "\nBefore threading: " << before;
    cout << "\nAfter threading: " << after;
    cout << "\nNULL pointers reduced by: "
         << before - after << "\n";

    return 0;
}

