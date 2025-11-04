#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Fungsi Bubble Sort untuk mengurutkan hasil BFS
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Masukkan jumlah teman dan edge: ";
    cin >> V >> E;

    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // karena graf tak berarah
    }

    int start;
    cout << "Masukkan titik start: ";
    cin >> start;

    vector<int> visited(V, 0);
    vector<int> hasil;  // menyimpan teman yang bisa dijangkau

    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        hasil.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    // Urutkan hasil BFS dengan Bubble Sort
    bubbleSort(hasil);

    // Tampilkan hasil akhir
    for (int node : hasil) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
