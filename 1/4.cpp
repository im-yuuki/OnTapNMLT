#include <iostream>
#include <string>
using namespace std;

bool is_palindrom(unsigned int x) {
    // Kiểm tra số nguyên tố
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    // Chuyển x thành chuỗi
    string s = to_string(x);
    // Đảo chuỗi
    string t = s;
    reverse(t.begin(), t.end());
    // Trả về kết quả so sánh
    return s == t;
}