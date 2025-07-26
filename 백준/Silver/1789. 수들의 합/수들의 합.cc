#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    long long s = 0;
    int n = 0;

    cin >> s;

    while (s > 0) {
        n++;
        s = s - n;
    }

    if (s < 0) {
        n--;
    }

    cout << n << '\n';

    return 0;
}