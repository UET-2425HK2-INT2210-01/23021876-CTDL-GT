/*
Cây ban đầu:
                   2
                 /    \
                1     10
                     /   \
                    6     13
                   /  \      \
                  3    8      20
                      /
                     7
Chèn 14,0,35:
                     2
                   /   \
                  1    10
                 /    /  \
                0    6    13
                    / \     \
                   3   8     20
                      /     /  \
                     7     14  35
Xóa 6,13,35:
                       2
                     /   \
                    1     10
                   /     /  \
                  0     7    14
                      /  \     \
                     3    8     20
Gỉa code:
Hàm Insert:
    Function insert(root, value):
    If root is NULL:
        Return new Node(value)  // Tạo node mới nếu cây rỗng

    If value < root.value:
        root.left = insert(root.left, value)  // Chèn vào cây con trái
    Else if value > root.value:
        root.right = insert(root.right, value)  // Chèn vào cây con phải

    Return root  // Trả về cây đã cập nhật

    Hàm Delete:
    Function delete(root, value):
    If root is NULL:
        Return NULL  // Không tìm thấy node cần xóa

    If value < root.value:
        root.left = delete(root.left, value)  // Tìm node cần xóa trong cây con trái
    Else if value > root.value:
        root.right = delete(root.right, value)  // Tìm node cần xóa trong cây con phải
    Else:
        // Node cần xóa được tìm thấy

        If root.left is NULL:  // Nếu chỉ có cây con phải hoặc không có con
            temp = root.right
            delete root  // Giải phóng bộ nhớ
            Return temp

        Else if root.right is NULL:  // Nếu chỉ có cây con trái
            temp = root.left
            delete root  // Giải phóng bộ nhớ
            Return temp

        Else:  // Nếu có cả hai con
            temp = findMin(root.right)  // Tìm node nhỏ nhất ở cây con phải
            root.value = temp.value  // Thay thế giá trị của root bằng giá trị của temp
            root.right = delete(root.right, temp.value)  // Xóa node nhỏ nhất trong cây con phải

    Return root  // Trả về cây đã cập nhật

*/
//Viết giả code cho insert và delete cho cả b1,b2