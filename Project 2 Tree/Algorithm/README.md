Algorithm: Threaded Binary Search Tree (TBST)
1. Start the program.
2. Define a node structure containing data, left and right pointers, and two Boolean flags lthread and rthread.
3. Initialize the root pointer to NULL.
4. Accept the number of nodes and input values from the user.
5. For each value, perform the following insertion steps:
- Create a new node and initialize its pointers and thread flags.
- If the tree is empty, make the new node the root.
- If the value is smaller than the current node, move to the left child if it is a child link; otherwise, insert the new node on the left.
- If the value is greater than the current node, move to the right child if it is a child link; otherwise, insert the new node on the right.
- Update the predecessor and successor threads accordingly.
- Reject duplicate values.
6. Find the leftmost node of the tree by following left child links until the left thread is encountered.
7. Perform inorder traversal:
- Display the current node's data.
- If the right pointer is a thread, move directly to the inorder successor.
- Otherwise, move to the leftmost node of the right subtree.
8. Repeat Step 7 until the current node becomes NULL.
9. Display the inorder traversal in sorted order.
10. Stop the program.
