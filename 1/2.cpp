#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sumLeft = 0;
    int sumRight = 0;
    for (int i = 0; i < n; i++) {
        sumRight += a[i];
    }
    for (int i = 0; i < n; i++) {
        sumRight -= a[i];
        if (sumLeft == sumRight) {
            cout << "true" << endl;
            delete[] a;
            return 0;
        }
        sumLeft += a[i];
    }
    cout << "false" << endl;
    delete[] a;
    return 0;
}