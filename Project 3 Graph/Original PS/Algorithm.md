## Algorithm

1. Start. Read the number of cities (V) and the cost matrix of roads (0 means no direct road).
2. Create three arrays for all cities:
   - `key[]` = the lowest cost found so far to connect the city (set to infinity)
   - `parent[]` = the city it is connected from (set to -1)
   - `inMST[]` = whether the city is already in the tree (set to false)
3. Set `key[0] = 0`, so the tree starts from city 0.
4. Repeat V times:
   1. Pick the city `u` that is not in the tree and has the smallest `key`.
   2. Mark `u` as in the tree (`inMST[u] = true`).
   3. For every city `v` that is next to `u` and not in the tree: if `cost(u, v) < key[v]`, set `key[v] = cost(u, v)` and `parent[v] = u`.
5. For every city `i` from 1 to V-1, print the road `parent[i] - i` with its cost, and add that cost to the total.
6. Print the total minimum construction cost.
7. If any city could not be reached (its key is still infinity), report that the cities are not fully connected.
8. Stop.
