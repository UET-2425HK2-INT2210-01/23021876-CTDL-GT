#include <iostream>
#include <vector>

using namespace std;

// Cấu trúc cạnh với 2 đỉnh (u, v) và trọng số w
struct Edge {
    int u, v, w;
};

// Lớp Disjoint Set Union (Union-Find)
class DSU {
    vector<int> parent; // Mảng lưu cha của mỗi đỉnh

public:
    // Khởi tạo với n đỉnh, mỗi đỉnh là cha của chính nó
    DSU(int n) : parent(n + 1) {
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }

    // Hàm tìm gốc của đỉnh u với nén đường (path compression)
    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);  // Gán lại cha của u là gốc
        return parent[u];
    }

    // Hợp nhất hai tập chứa u và v
    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;  // Cùng tập thì bỏ qua, tránh chu trình
        parent[pu] = pv;             // Hợp nhất: gán gốc của u là gốc của v
        return true;
    }
};

// Hàm sắp xếp cạnh tăng dần theo trọng số (selection sort tự viết)
void sortEdges(vector<Edge>& edges) {
    int n = edges.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (edges[j].w < edges[minIdx].w)
                minIdx = j;
        if (minIdx != i) {
            Edge temp = edges[i];
            edges[i] = edges[minIdx];
            edges[minIdx] = temp;
        }
    }
}

int main() {
    // Dữ liệu cạnh cố định (không nhập từ file hay bàn phím)
    vector<Edge> edges = {
        {1, 2, 10}, {1, 5, 12}, {2, 5, 9}, {2, 3, 8}, {5, 7, 1},
        {5, 6, 3}, {3, 6, 7}, {6, 7, 3}, {3, 7, 13}, {3, 4, 8},
        {3, 8, 5}, {7, 8, 6}, {4, 8, 9}, {4, 9, 2}, {8, 9, 11}
    };

    int n = 9;  // Số lượng đỉnh trong đồ thị
    DSU dsu(n); // Khởi tạo DSU cho n đỉnh

    sortEdges(edges);  // Sắp xếp các cạnh theo trọng số tăng dần

    int totalWeight = 0; // Tổng trọng số cây khung nhỏ nhất
    cout << "Cac canh trong cay khung nho nhat:\n";

    // Duyệt qua các cạnh theo thứ tự đã sắp xếp
    for (const Edge& e : edges) {
        // Nếu hai đỉnh chưa cùng tập -> thêm cạnh vào cây khung
        if (dsu.unite(e.u, e.v)) {
            totalWeight += e.w;
            cout << e.u << " - " << e.v << " : " << e.w << '\n';
        }
    }

    // In tổng trọng số cây khung nhỏ nhất
    cout << "Tong trong so cay khung: " << totalWeight << '\n';
    return 0;
}
