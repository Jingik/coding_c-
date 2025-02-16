#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1010;
int N;
int Arr[MAX];
int DP[MAX];

void Input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> Arr[i];
    }
}

void Solution() {
    int Answer = 0;
    
    for (int i = 1; i <= N; i++) {
        DP[i] = 1;
        for (int j = i - 1; j >= 1; j--) {
            if (Arr[i] > Arr[j]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        Answer = max(Answer, DP[i]);
    }

    cout << Answer << "\n";
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}
