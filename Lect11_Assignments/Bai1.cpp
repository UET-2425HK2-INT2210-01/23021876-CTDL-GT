#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Hằng vô cực cho trọng số
const long long INF = 1000000000000000LL;

struct Edge {
    int from;       // đỉnh bắt đầu
    int to;         // đỉnh kết thúc
    long long w;    // trọng số (dirty level)
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- 1. Đọc dữ liệu ---
    int numCities, numRoads, startCity, endCity;
    cin >> numCities >> numRoads >> startCity >> endCity;

    // Lưu tất cả các đường (cung)
    vector<Edge> edges;
    edges.reserve(numRoads);
    for (int i = 0; i < numRoads; i++) {
        int u, v;
        long long d;
        cin >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    // --- 2. Bellman–Ford để tìm đường từ startCity → endCity ---
    // 2.1. Khởi tạo mảng khoảng cách và mảng tiền thúc (predecessor)
    vector<long long> dist(numCities + 1, INF);
    vector<int> predecessor(numCities + 1, -1);

    // Khoảng cách từ startCity đến chính nó là 0
    dist[startCity] = 0;

    // 2.2. Relax tất cả các cạnh tối đa (numCities-1) lần
    for (int iter = 1; iter < numCities; iter++) {
        bool anyRelax = false;
        for (int i = 0; i < numRoads; i++) {
            int u = edges[i].from;
            int v = edges[i].to;
            long long w = edges[i].w;
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                predecessor[v] = u;
                anyRelax = true;
            }
        }
        // Nếu trong một vòng không relax được nữa thì dừng sớm
        if (!anyRelax) break;
    }

    // 2.3. In kết quả cho Bellman–Ford
    if (dist[endCity] >= INF/2) {
        // Không có đường đi tới endCity
        cout << "INF\n\n";
    } else {
        // In tổng dirty level
        cout << dist[endCity] << "\n";

        // Lấy đường đi ngắn nhất bằng cách đi ngược từ endCity về startCity
        vector<int> path;
        int cur = endCity;
        while (cur != -1) {
            path.push_back(cur);
            cur = predecessor[cur];
        }
        // Đảo mảng path để được thứ tự startCity → ... → endCity
        int L = 0, R = (int)path.size() - 1;
        while (L < R) {
            int tmp = path[L];
            path[L] = path[R];
            path[R] = tmp;
            L++; R--;
        }

        // In đường đi
        for (int i = 0; i < (int)path.size(); i++) {
            if (i) cout << ' ';
            cout << path[i];
        }
        cout << "\n";
    }

    // --- 3. Floyd–Warshall tính mọi cặp ngắn nhất ---
    // 3.1. Khởi ma trận distAll[i][j]
    vector<vector<long long>> distAll(numCities + 1,
                                      vector<long long>(numCities + 1, INF));
    // Đường từ một thành phố đến chính nó = 0
    for (int i = 1; i <= numCities; i++) {
        distAll[i][i] = 0;
    }
    // Gán trọng số các cung (giữ min nếu có nhiều cung cùng u→v)
    for (int i = 0; i < numRoads; i++) {
        int u = edges[i].from;
        int v = edges[i].to;
        long long w = edges[i].w;
        if (w < distAll[u][v]) {
            distAll[u][v] = w;
        }
    }

    // 3.2. Ba vòng lặp cập nhật
    for (int k = 1; k <= numCities; k++) {
        for (int i = 1; i <= numCities; i++) {
            if (distAll[i][k] >= INF) continue;
            for (int j = 1; j <= numCities; j++) {
                if (distAll[k][j] < INF &&
                    distAll[i][k] + distAll[k][j] < distAll[i][j]) {
                    distAll[i][j] = distAll[i][k] + distAll[k][j];
                }
            }
        }
    }

    // 3.3. In ma trận kết quả
    for (int i = 1; i <= numCities; i++) {
        for (int j = 1; j <= numCities; j++) {
            if (distAll[i][j] >= INF/2) 
                cout << "INF";
            else 
                cout << distAll[i][j];
            if (j < numCities) cout << ' ';
        }
        cout << "\n";
    }

    return 0;
}
