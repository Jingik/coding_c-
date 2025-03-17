#include <iostream>
#define MAX 101
#define MOD 1000000000
typedef long long ll;
using namespace std;

int N;
ll Answer;
ll DP[MAX][11];

void Input() {
    cin >> N;
}

void Solution() {
    for (int i = 1; i <= 9; i++) {
        DP[1][i] = 1;
    }
    DP[1][0] = 0;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) { 
            if (j == 0) DP[i][j] = DP[i - 1][1] % MOD; 
            else if (j == 9) DP[i][j] = DP[i - 1][8] % MOD; 
            else DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD; 
        }
    }

    for (int i = 0; i <= 9; i++) {
        Answer = (Answer + DP[N][i]) % MOD;
    }

    cout << Answer << '\n';
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
