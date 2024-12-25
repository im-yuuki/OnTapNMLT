#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    if (str.size() == 0) return 0;
    if (str[0] >= 'A' && str[0] <= 'Z') {
        cout << str << endl;
    } else {
        cout << str[0] << str.size() << str[str.size() - 1] << endl;
    }
}