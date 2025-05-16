#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int>> adj;  // Danh sách kề
bool visited[1001];       // Mảng đánh dấu đã thăm

// Hàm DFS để duyệt đồ thị
void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

// Hàm BFS để duyệt đồ thị
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);  // Khởi tạo danh sách kề
    memset(visited, false, sizeof(visited));

    // Nhập các cạnh
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);  // Đồ thị vô hướng
    }

    int components = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            bfs(i);  // Duyệt bằng BFS
            components++;
        }
    }

    cout << components << endl;
    return 0;
}
