
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    // Khởi tạo danh sách kề
    vector<vector<int>> adj_list(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);  // Đồ thị có hướng
    }

    // Khởi tạo mảng đánh dấu và khoảng cách
    vector<bool> visited(adj_list.size(), false);
    vector<int> distances(adj_list.size(), -1); // -1 nghĩa là chưa đi đến

    queue<int> q;

    // Bắt đầu BFS từ đỉnh X
    q.push(X);
    visited[X] = true;
    distances[X] = 0;

    while (!q.empty()) {
        int v = q.front(); q.pop();

        for (int v_next : adj_list[v]) {
            if (!visited[v_next]) {
                visited[v_next] = true;
                q.push(v_next);
                distances[v_next] = distances[v] + 1;
            }
        }
    }

    // In ra kết quả là khoảng cách ngắn nhất từ X đến Y
    cout << distances[Y] << endl;

    return 0;
}
