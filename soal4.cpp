#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> visited; // Menyimpan hari ke berapa seseorang terinfeksi

void dfs(int node, int day) {
    for (int neighbor : graph[node]) {
        if (visited[neighbor] == -1) {
            visited[neighbor] = day + 1; // Anak terinfeksi keesokan harinya
            dfs(neighbor, day + 1);
        }
    }
}

int main() {
    int V, E;
    cout << "Jumlah vertex dan edge: ";
    cin >> V >> E;

    graph.assign(V, {});
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // graf tak berarah
    }

    int S, K;
    cout << "Node Awal dan Hari Terinfeksi: ";
    cin >> S >> K;

    visited.assign(V, -1);
    visited[S] = 0; // hari 0
    dfs(S, 0);

    // Kumpulkan semua orang yang baru terinfeksi di hari ke-K
    vector<int> result;
    for (int i = 0; i < V; i++) {
        if (visited[i] == K) {
            result.push_back(i);
        }
    }

    cout << "Node terinfeksi: ";
    if (result.empty()) {
        cout << "(TIDAK ADA)";
    } else {
        sort(result.begin(), result.end());
        for (int x : result) cout << x << " ";
    }
    cout << endl;

    return 0;
}
//Masukkan jawaban disini
