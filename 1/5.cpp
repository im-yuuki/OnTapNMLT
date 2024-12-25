#include <iostream>
using namespace std;

int a[35];

int main() {
    a[0] = a[1] = a[2] = 1;
    for (int i = 3; i < 35; i++) {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << a[n - 1] << endl;
    }
}

