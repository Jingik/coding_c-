#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    long long N;
    cin >> N;

    if (N % 2 == 0) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
