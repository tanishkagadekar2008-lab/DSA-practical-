## Tite
Minimum Cost Road Network using Prim's Algorithm with Road Update and Connectivity Check

## Complexity Analysis

Here V is the number of cities. The graph is stored as an adjacency matrix.

| Part of the program | Time complexity | Why |
|---|---|---|
| Show roads | O(V²) | Every cell of the matrix is checked once |
| Pick the smallest key | O(V) per pick | One scan over all cities, done V times |
| Update neighbours | O(V) per city | One scan of the matrix row, done V times |
| **Prim's algorithm (whole)** | **O(V²)** | V picks, each costing O(V) |
| Display selected roads with running total | O(V) | One line per selected road, at most V - 1 roads |
| Disconnected graph check | O(V) | Compare picked cities with V and list the unreachable ones |
| Update a road, then run Prim's again | O(V²) | O(1) to change the matrix, O(V²) to rerun Prim's |

**Space complexity:** O(V²) for the cost matrix, plus O(V) for the `key`, `parent` and `inMST` arrays. The total is O(V²).

**Notes**
- The time is O(V²) in every case, whether the graph has few roads or many, because the matrix is always scanned.
- With an adjacency list and a priority queue (min-heap), Prim's algorithm can run in O(E log V). That is better for graphs with few roads.
- For this program, V = 6, so the work is very small.

## Conclusion

This project represents cities as vertices and roads as weighted edges, and uses Prim's algorithm to build the minimum spanning tree with the least total construction cost. Updating a road's cost and running Prim's again shows how the selected roads and the total cost change. The connectivity check reports whether a spanning tree can be formed. The matrix-based version runs in O(V²), which is simple and works well for small graphs.
