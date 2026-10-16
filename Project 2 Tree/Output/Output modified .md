
Enter number of nodes: 5
Enter value: 40
Enter value: 20
Enter value: 60
Enter value: 10
Enter value: 30

Inorder Traversal: 10 20 30 40 60

THREADED BST POINTER REPRESENTATION

Node: 10
Left Pointer: Thread -> NULL
Right Pointer: Thread -> 20
Inorder Predecessor: None
Inorder Successor: 20

Node: 20
Left Pointer: Child Link -> 10
Right Pointer: Child Link -> 30
Inorder Predecessor: 10
Inorder Successor: 30

Node: 30
Left Pointer: Thread -> 20
Right Pointer: Thread -> 40
Inorder Predecessor: 20
Inorder Successor: 40

Node: 40
Left Pointer: Child Link -> 20
Right Pointer: Child Link -> 60
Inorder Predecessor: 30
Inorder Successor: 60

Node: 60
Left Pointer: Thread -> 40
Right Pointer: Thread -> NULL
Inorder Predecessor: 40
Inorder Successor: None

NULL POINTER COMPARISON
Total nodes: 5
Before threading: 6
After threading: 2
NULL pointers reduced by: 4
<img width="960" height="540" alt="Screenshot 2026-10-17 003054" src="https://github.com/user-attachments/assets/7462c763-b16c-4afc-b7ed-971950d65681" />
<img width="960" height="540" alt="Screenshot 2026-10-17 003058" src="https://github.com/user-attachments/assets/087a011c-c2b8-429d-a8f9-a2009c93043a" />

