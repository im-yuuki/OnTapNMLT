int* posDivisorOfX(int* a, int n, int x, int& returnSize) {
    // Cấp phát động mảng a (mục đích để không bị xoá sau khi hàm kết thúc)
    int* answer = new int[n];
    returnSize = 0;
    for (int i = 0; i < n; i++) {
        // Kiểm tra a[i] có phải là ước của x không
        if (a[i] == 0) {
            // Tránh chia cho 0
            continue;
        }
        if (x % a[i] == 0) {
            answer[returnSize++] = i;
        }
    }
    // Trả về con trỏ đến địa chỉ của mảng động
    return answer;
}