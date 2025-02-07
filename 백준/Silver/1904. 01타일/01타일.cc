#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int prev2 = 1;  
    int prev1 = 2; 
    int curr;

    if (N == 1) {
        cout << 1 << '\n';
        return 0;
    }

    for (int i = 3; i <= N; i++) {
        curr = (prev1 + prev2) % 15746;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1 << '\n';
    return 0;
}
