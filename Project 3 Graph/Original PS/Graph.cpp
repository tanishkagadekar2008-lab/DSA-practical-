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

    for (int count = 0; count < V; count++) {
        int u = minKey(key, inMST);
        if (u == -1) break;
        inMST[u] = true;
        for (int v = 0; v < V; v++) {
            if (cost[u][v] > 0 && !inMST[v] && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;
    bool connected = true;
    cout << "\nRoads selected by Prim's algorithm:" << endl;
    for (int i = 1; i < V; i++) {
        if (parent[i] == -1) {
            connected = false;
        } else {
            cout << city[parent[i]] << " - " << city[i] << " : " << cost[i][parent[i]] << endl;
            total += cost[i][parent[i]];
        }
    }
    if (!connected)
        cout << "Some cities cannot be connected." << endl;
    cout << "\nTotal minimum construction cost: " << total << " crore" << endl;
}

int main() {
    showRoads();
    primMST();
    return 0;
}
