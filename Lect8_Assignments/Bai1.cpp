#include <iostream>
using namespace std;

// Hàm hoán đổi giá trị của hai biến
void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

// Hàm partition dùng trong quicksort
int partition(float arr[], int low, int high) {
    float pivot = arr[high]; // chọn phần tử cuối làm pivot
    int i = low - 1; // chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // đưa phần tử nhỏ hơn pivot về bên trái
        }
    }
    swap(arr[i + 1], arr[high]); // đưa pivot về đúng vị trí
    return i + 1; // trả về vị trí mới của pivot
}

// Hàm quicksort chính
void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // tìm chỉ số chia mảng

        quickSort(arr, low, pi - 1); // sắp xếp nửa trái
        quickSort(arr, pi + 1, high); // sắp xếp nửa phải
    }
}

int main() {
    int n;
    cin >> n; // nhập số lượng phần tử

    float arr[100]; // khai báo mảng chứa tối đa 100 phần tử

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // nhập các phần tử
    }

    quickSort(arr, 0, n - 1); // gọi hàm quicksort

    for (int i = 0; i < n; i++) {
        cout << arr[i]; // in ra phần tử
        if (i != n - 1) cout << " "; // chèn khoảng trắng giữa các phần tử
    }

    return 0;
}
