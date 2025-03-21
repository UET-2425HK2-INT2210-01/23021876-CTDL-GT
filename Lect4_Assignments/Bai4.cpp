#include <iostream>
using namespace std;

struct Student {
    int id;
    char name[101];
    char className[31];
};

Student students[1000]; // Mảng lưu tối đa 1000 sinh viên
int countStudent = 0;   // Số lượng sinh viên hiện tại

// Thêm hoặc cập nhật sinh viên
void insertStudent(int id, char name[], char className[]) {
    // Kiểm tra xem ID đã tồn tại chưa, nếu có thì cập nhật
    for (int i = 0; i < countStudent; i++) {
        if (students[i].id == id) {
            // Cập nhật tên và lớp
            int j = 0;
            while (name[j]) {
                students[i].name[j] = name[j];
                j++;
            }
            students[i].name[j] = '\0';

            j = 0;
            while (className[j]) {
                students[i].className[j] = className[j];
                j++;
            }
            students[i].className[j] = '\0';
            return;
        }
    }

    // Thêm sinh viên mới nếu ID chưa tồn tại
    students[countStudent].id = id;

    int j = 0;
    while (name[j]) {
        students[countStudent].name[j] = name[j];
        j++;
    }
    students[countStudent].name[j] = '\0';

    j = 0;
    while (className[j]) {
        students[countStudent].className[j] = className[j];
        j++;
    }
    students[countStudent].className[j] = '\0';

    countStudent++;
}

// Xoá sinh viên theo ID
void deleteStudent(int id) {
    for (int i = 0; i < countStudent; i++) {
        if (students[i].id == id) {
            // Dời các phần tử sau lên để xóa
            for (int j = i; j < countStudent - 1; j++) {
                students[j] = students[j + 1];
            }
            countStudent--;
            return;
        }
    }
}

// In thông tin sinh viên
void infor(int id) {
    for (int i = 0; i < countStudent; i++) {
        if (students[i].id == id) {
            cout << students[i].name << "," << students[i].className << endl;
            return;
        }
    }
    cout << "NA,NA" << endl;
}

// Hàm chính
int main() {
    char command[200];

    while (cin.getline(command, 200)) {
        // Nếu là lệnh Insert
        if (command[0] == 'I' && command[1] == 'n') {
            int id = 0, i = 7;
            while (command[i] != ',') {
                id = id * 10 + (command[i] - '0');
                i++;
            }
            i++; // bỏ dấu ,

            char name[101], className[31];
            int j = 0;

            // Lấy tên
            while (command[i] != ',') {
                name[j++] = command[i++];
            }
            name[j] = '\0';
            i++; // bỏ dấu ,

            j = 0;
            // Lấy lớp
            while (command[i] != ')') {
                className[j++] = command[i++];
            }
            className[j] = '\0';

            insertStudent(id, name, className);
        }

        // Nếu là lệnh Delete
        else if (command[0] == 'D') {
            int id = 0, i = 7;
            while (command[i] != ')') {
                id = id * 10 + (command[i] - '0');
                i++;
            }
            deleteStudent(id);
        }

        // Nếu là lệnh Infor
        else if (command[0] == 'I' && command[1] == 'n' && command[2] == 'f') {
            int id = 0, i = 6;
            while (command[i] != ')') {
                id = id * 10 + (command[i] - '0');
                i++;
            }
            infor(id);
        }
    }

    return 0;
}
