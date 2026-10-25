## Algorithm

1. Start. Set the cities and the cost matrix (0 means no road).
2. Show the menu and read the choice. Repeat until the user chooses Exit.
3. Show roads: print every road with its cost.
4. Update road (A):
   1. Read city 1, city 2 and the new cost. Reject the input if the cities are invalid or the same, or if the cost is negative.
   2. Set the cost in both directions of the matrix (0 removes the road, a cost on a missing road adds it).
   3. Run Prim's algorithm again (Step 5).
5. Prim's algorithm:
   1. For all cities set `key = INFINITY`, `parent = -1`, `inMST = false`. Set `key[0] = 0`. Set `total = 0` and `picked = 0`.
   2. Repeat V times:
      1. Pick the city `u` not in the tree with the smallest `key`. If there is none (all remaining keys are infinity), stop the loop.
      2. Mark `u` as in the tree and add 1 to `picked`.
      3. If `u` has a parent (B): print the road `parent[u] - u` with its weight `key[u]`, add the weight to `total`, and print the running total.
      4. For every city `v` next to `u` and not in the tree: if `cost(u, v) < key[v]`, set `key[v] = cost(u, v)` and `parent[v] = u`.
   3. If `picked == V` (C): print that the graph is connected, a spanning tree can be formed, and the total minimum cost.
   4. Otherwise (C): print that the graph is disconnected and a spanning tree cannot be formed, list the cities not reachable from city 0, and print the cost of the connected part.
6. On Exit, stop.
