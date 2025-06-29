#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double minimum_hits(double A, int B) {
    vector<vector<double>> dp(B + 1, vector<double>(B + 1, 0.0));

    dp[0][0] = 1.0;

    for (int i = 1; i <= B; i++) {
        for (int j = 0; j <= i; j++) {
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1] * A;  
            }
            dp[i][j] += dp[i - 1][j] * (1 - A); 
        }
    }

    double cumulative_prob = 0.0;
    for (int c = 0; c <= B; c++) {
        cumulative_prob += dp[B][c];
        if (cumulative_prob >= 0.05) {
            return c;
        }
    }

    return B;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    double A;
    int B;
    cin >> A >> B;

    cout << minimum_hits(A, B) << endl;

    return 0;
}
