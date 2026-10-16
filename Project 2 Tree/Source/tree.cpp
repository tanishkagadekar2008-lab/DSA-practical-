
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
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    Node* temp = createNode(value);

    if (parent == NULL)
    {
        root = temp;
    }
    else if (value < parent->data)
    {
        temp->left = parent->left;
        temp->right = parent;
        parent->lthread = false;
        parent->left = temp;
    }
    else
    {
        temp->right = parent->right;
        temp->left = parent;
        parent->rthread = false;
        parent->right = temp;
    }

    return root;
}

Node* leftmost(Node* ptr)
{
    if (ptr == NULL)
        return NULL;

    while (ptr->lthread == false)
        ptr = ptr->left;

    return ptr;
}

void inorder(Node* root)
{
    Node* ptr = leftmost(root);

    while (ptr != NULL)
    {
        cout << ptr->data << " ";

        if (ptr->rthread == true)
            ptr = ptr->right;
        else
            ptr = leftmost(ptr->right);
    }
}

int main()
{
    Node* root = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}

