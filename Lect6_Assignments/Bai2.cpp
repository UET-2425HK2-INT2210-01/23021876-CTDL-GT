/*
Cây ban đầu:
                 2        
                /  \
               1   10
              / \  / \
             6   3 8  7
            / \
           13 20

Max:
                    20
                   /  \
                  13   8
                 / \  / \
                10  3 2  7
               /  \
              1    6
Chèn 14,0,35:
                        35
                    /       \
                   14        20
                  /  \      /  \
                 10   13   8    7
                /  \  / \  /
               1    6 3  0 2
Xóa 6,13,35:
                       20
                    /      \
                  14        8
                 /  \      /  \
               10    3    2    7
              /      /      
             1      0    
 Giả code:
 Hàm isert:
 Function insert(value):
    If size == MAX_SIZE:
        Print "Heap is full"
        Return

    size = size + 1  // Tăng kích thước heap
    i = size - 1
    array[i] = value  // Thêm giá trị vào cuối heap

    // Điều chỉnh để duy trì tính chất của Heap (Heapify Up)
    While i > 0 AND array[parent(i)] > array[i]:  // Với Min-Heap
        Swap array[i] and array[parent(i)]
        i = parent(i)

Function parent(i):
    Return (i - 1) / 2  // Chỉ số của nút cha

    Hàm Delete:
    Function delete(value):
    i = findIndex(value)  // Tìm chỉ số của phần tử cần xóa
    If i == -1:
        Print "Value not found"
        Return

    Swap array[i] and array[size - 1]  // Đưa phần tử cần xóa xuống cuối
    size = size - 1  // Giảm kích thước Heap

    // Điều chỉnh Heap để duy trì tính chất của Heap (Heapify Down)
    heapify(i)

Function findIndex(value):
    For i = 0 to size - 1:
        If array[i] == value:
            Return i
    Return -1

Function heapify(i):
    smallest = i
    left = leftChild(i)
    right = rightChild(i)

    If left < size AND array[left] < array[smallest]:  // Với Min-Heap
        smallest = left

    If right < size AND array[right] < array[smallest]:  // Với Min-Heap
        smallest = right

    If smallest != i:
        Swap array[i] and array[smallest]
        heapify(smallest)

Function leftChild(i):
    Return 2 * i + 1

Function rightChild(i):
    Return 2 * i + 2


*/