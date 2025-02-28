#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n;
    cout << " Nhập số lượng số nguyên (n): ";
    cin >> n;
    vector<int> numbers(n);
    cout << "Nhập danh sách số nguyên (các số cách nhau bởi dấu cách): ";
    for (int i=0; i<n; ++i){
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    cout << "Danh sách số nguyên đã được sắp xếp theo thứ tự tăng dần:";
    for(int i=0; i<n; ++i){
        cout << numbers[i] << " ";
    }
    cout << endl;
    return 0;
}    
