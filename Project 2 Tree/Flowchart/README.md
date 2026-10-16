flowchart TD
    A([Start]) --> B[Initialize root = NULL]
    B --> C[/Enter number of nodes n/]
    C --> D[i = 0]
    D --> E{i < n?}
    E -- Yes --> F[/Enter value/]
    F --> G[Search insertion position]
    G --> H{Duplicate value?}
    H -- Yes --> I[Display duplicate message]
    H -- No --> J[Create new node]
    I --> K[i = i + 1]
    J --> L{Parent is NULL?}
    L -- Yes --> M[Set new node as root]
    L -- No --> N{Value < parent data?}
    N -- Yes --> O[Update left child and threads]
    N -- No --> P[Update right child and threads]
    M --> K
    O --> K
    P --> K
    K --> E
    E -- No --> Q[Find leftmost node]
    Q --> R{Current node is not NULL?}
    R -- Yes --> S[Display current node data]
    S --> T{Right pointer is a thread?}
    T -- Yes --> U[Move to right thread]
    T -- No --> V[Find leftmost node of right subtree]
    U --> R
    V --> R
    R -- No --> W([Stop])


