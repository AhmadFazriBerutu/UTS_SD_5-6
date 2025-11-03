//Masukkan jawaban disini
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int V, E;
    cout << "Jumlah vertex dan edge: ";
    cin >> V >> E;

    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // karena graf tak berarah
    }

    int S, K;
    cout << "Node Awal dan Hari Terinfeksi: ";
    cin >> S >> K;

    vector<int> visited(V, -1); // -1 artinya belum terinfeksi
    queue<int> q;

    visited[S] = 0; // orang pertama terinfeksi di hari ke-0
    q.push(S);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (visited[neighbor] == -1) {
                visited[neighbor] = visited[node] + 1;
                q.push(neighbor);
            }
        }
    }

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

return 0;
}

// Penjelasan :
// Program ini membuat sebuah graph dari inputan
// Program ini menggunakan Queue untuk melakukan BFS untuk penyebaran infeksi secara berlapis
// Program ini akan di ulang sampai Queue kosong ( semua node yang bisa terinfeksi sudah diproses )
// Program akan menampilkan daftar node yang terinfeksi di hari terinfeksi//Masukkan jawaban disini
