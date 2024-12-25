#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double height[5];
    for (int i = 0; i < 5; i++) {
        cin >> height[i];
    }
    double highest = height[0];
    double shortest = height[0];
    double sum = height[0];
    for (int i = 1; i < 5; i++) {
        if (height[i] > highest) {
            highest = height[i];
        }
        if (height[i] < shortest) {
            shortest = height[i];
        }
        sum += height[i];
    }
    cout << fixed << setprecision(2) << highest << ' ' << shortest << ' ' << sum / 5 << endl;
}