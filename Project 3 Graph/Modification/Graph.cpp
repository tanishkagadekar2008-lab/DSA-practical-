#include <iostream>
#include <string>
using namespace std;
 
const int V = 6;
const int INF = 99999;
 
string city[V] = {"Nashik", "Sangamner", "Pune", "Mumbai", "Aurangabad", "Nagpur"};
 
int cost[V][V] = {
    {0,   40,  130, 100, 120, 0},
    {40,  0,   70,  0,   90,  0},
    {130, 70,  0,   80,  140, 400},
    {100, 0,   80,  0,   200, 0},
    {120, 90,  140, 200, 0,   250},
    {0,   0,   400, 0,   250, 0}
};
 
void showRoads() {
    cout << "Possible roads and construction cost (in crore):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (cost[i][j] > 0)
                cout << city[i] << " - " << city[j] << " : " << cost[i][j] << endl;
        }
    }
}
 
int minKey(int key[], bool inMST[]) {
    int min = INF;
    int index = -1;
    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            index = v;
        }
    }
    return index;
}
 
void primMST() {
    int key[V];
    int parent[V];
    bool inMST[V];
 
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        parent[i] = -1;
        inMST[i] = false;
    }
    key[0] = 0;
 
    int total = 0;
    int picked = 0;
    int step = 0;
 
    cout << "\nSelected roads (in order):" << endl;
    for (int count = 0; count < V; count++) {
        int u = minKey(key, inMST);
        if (u == -1) break;
        inMST[u] = true;
        picked++;
 
        if (parent[u] != -1) {
            step++;
            total += key[u];
            cout << step << ". " << city[parent[u]] << " - " << city[u]
                 << " : " << key[u] << " | Running total: " << total << endl;
        }
 
        for (int v = 0; v < V; v++) {
            if (cost[u][v] > 0 && !inMST[v] && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }
 
    if (picked == V) {
        cout << "\nGraph is connected. Spanning tree can be formed." << endl;
        cout << "Total minimum construction cost: " << total << " crore" << endl;
    } else {
        cout << "\nGraph is disconnected. Spanning tree cannot be formed." << endl;
        cout << "Cities not reachable from " << city[0] << ":";
        for (int i = 0; i < V; i++) {
            if (!inMST[i]) cout << " " << city[i];
        }
        cout << endl;
        cout << "Cost of the connected part: " << total << " crore" << endl;
    }
}
 
void updateRoad() {
    int a, b, w;
    cout << "City 1 number: ";
    cin >> a;
    cout << "City 2 number: ";
    cin >> b;
    if (a < 0 || a >= V || b < 0 || b >= V || a == b) {
        cout << "Invalid cities." << endl;
        return;
    }
    cout << "New cost (0 to remove road): ";
    cin >> w;
    if (w < 0) {
        cout << "Invalid cost." << endl;
        return;
    }
 
    int old = cost[a][b];
    cost[a][b] = w;
    cost[b][a] = w;
 
    cout << city[a] << " - " << city[b] << ": ";
    if (old == 0 && w > 0) cout << "new road added with cost " << w << endl;
    else if (w == 0) cout << "road removed" << endl;
    else cout << "cost changed from " << old << " to " << w << endl;
 
    primMST();
}
 
int main() {
    cout << "Cities: ";
    for (int i = 0; i < V; i++)
        cout << i << "=" << city[i] << " ";
    cout << endl;
 
    int choice;
    while (true) {
        cout << "\n1.Show Roads  2.Run Prim's MST  3.Update Road Cost  0.Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
 
        if (choice == 1) showRoads();
        else if (choice == 2) primMST();
        else if (choice == 3) updateRoad();
        else if (choice == 0) { cout << "Bye!" << endl; break; }
        else cout << "Invalid choice." << endl;
    }
    return 0;
}
 
