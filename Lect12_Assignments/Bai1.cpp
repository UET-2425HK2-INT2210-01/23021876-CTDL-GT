#include <iostream>    
#include <vector>       
#include <queue>        

using namespace std;

int main() {
    int n, m;
    cout << "Nhap n va m: ";
    cin >> n >> m;  // Nhập số công việc và số ràng buộc

    vector<vector<int>> adj(n + 1);  // Danh sách kề, adj[u] chứa các công việc v mà u phải làm trước
    vector<int> indegree(n + 1, 0);  // Mảng đếm bậc vào của mỗi công việc

    cout << "Nhap " << m << " cap cong viec u v (u truoc v):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;              // Nhập cặp công việc: u phải làm trước v
        adj[u].push_back(v);        // Thêm v vào danh sách kề của u
        indegree[v]++;              // Tăng bậc vào của v
    }

    queue<int> q;                   // Hàng đợi để xử lý các công việc có bậc vào = 0
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0)       // Nếu công việc i không bị phụ thuộc bởi công việc nào khác
            q.push(i);              // Thêm i vào hàng đợi
    }

    vector<int> order;              // Lưu thứ tự công việc đã sắp xếp (kết quả topo sort)
    while (!q.empty()) {
        int u = q.front(); q.pop(); // Lấy công việc đầu tiên ra khỏi hàng đợi
        order.push_back(u);         // Thêm công việc này vào kết quả

        for (int v : adj[u]) {      // Duyệt tất cả các công việc phụ thuộc vào u
            indegree[v]--;          // Giảm bậc vào của v vì u đã được xử lý
            if (indegree[v] == 0)   // Nếu sau khi giảm, v không còn phụ thuộc gì nữa
                q.push(v);          // Thêm v vào hàng đợi
        }
    }

    // Nếu số công việc được sắp xếp không bằng tổng số công việc => có chu trình
    if (order.size() != n) {
        cout << "Khong the sap xep: co chu trinh hoac dau vao khong hop le." << endl;
    } else {
        cout << "Thu tu cong viec hop le: ";
        for (int job : order) {
            cout << job << " ";     // In ra thứ tự công việc hợp lệ
        }
        cout << endl;
    }

    return 0;  
}
