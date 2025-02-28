#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // Để sử dụng numeric_limits

using namespace std;
int main() {
    vector<double> numbers(5);
    cout << "Nhập 5 số thực (các số cách nhau bởi dấu cách): ";
    for (int i = 0; i < 5; ++i) {
        cin >> numbers[i];
    }
    double maxNumber = numeric_limits<double>::lowest(); // Khởi tạo giá trị nhỏ nhất có thể
    double minNumber = numeric_limits<double>::max(); // Khởi tạo giá trị lớn nhất có thể

    for (double number : numbers) {
        if (number > maxNumber) {
            maxNumber = number;
        }
        if (number < minNumber) {
            minNumber = number;
        }
    }
    double sum = maxNumber + minNumber;
    cout << "Tổng của số lớn nhất và số bé nhất là: " << sum << endl;
    return 0;
}

