#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int it;
    cin >> it;

    int N = it;
    int count = 0;

    do {
        int a = N / 10;
        int b = N % 10;
        N = b * 10 + (a + b) % 10;
        count++;
    } while (N != it);

    cout << count;
    return 0;
}
