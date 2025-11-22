#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    if (n == 1 || n == 3) {
        cout << -1 << endl;
        return 0;
    }

    int count5 = n / 5;
    int remainder = n % 5;

    if (remainder % 2 == 0) {
        cout << count5 + remainder / 2 << endl;
    } else {
        cout << (count5 - 1) + (remainder + 5) / 2 << endl;
    }

    return 0;
}
