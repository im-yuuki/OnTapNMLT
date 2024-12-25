#include <iostream>
using namespace std;

int main() {
    string num;
    cin >> num;
    int count = 0;
    for (int i = 0; i < num.size(); i++) {
        if (num[i] == '0' || num[i] == '3' || num[i] == '6' || num[i] == '9') {
            count++;
        }
    }
    if (count == 0) return 0;
    cout << count << endl;
}