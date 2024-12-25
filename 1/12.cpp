#include <iostream>
using namespace std;

string solve(const string& num, const int k) {
    string ans;
    int lastIndex = -1;
    for (int i = 0; i < k; i++) {
        int maxIndex = lastIndex + 1;
        for (int j = maxIndex; j <= num.size() - k + ans.size(); j++) {
            if (num[j] > num[maxIndex]) maxIndex = j;
        }
        ans += num[maxIndex];
        lastIndex = maxIndex;
    }
    return ans;
}

int main() {
    string num;
    int k;
    cin >> num >> k;
    cout << solve(num, k) << endl;
    return 0;
}