#include <iostream>
using namespace std;

const int MAX_EDGE = 100;

int main() {
    int n, m;
    cin >> n >> m;
    int a[MAX_EDGE][MAX_EDGE];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    int minRow[MAX_EDGE], maxCol[MAX_EDGE];
    for (int i = 0; i < n; i++) {
        minRow[i] = a[i][0];
        for (int j = 1; j < m; j++) {
            if (a[i][j] < minRow[i]) minRow[i] = a[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        maxCol[j] = a[0][j];
        for (int i = 1; i < n; i++) {
            if (a[i][j] > maxCol[j]) maxCol[j] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (a[i][j] == minRow[i] && a[i][j] == maxCol[j]) {
            cout << i + 1 << ' ' << j + 1 << endl;
            cout << a[i][j] << endl;
        }
    }
}