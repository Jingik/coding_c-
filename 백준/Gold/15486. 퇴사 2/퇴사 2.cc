#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> T, P;
int dp[1500001]; 

int solve(int day) {
    if (day > N) return 0;  
    if (dp[day] != -1) return dp[day];  

    int maxProfit = solve(day + 1);

    if (day + T[day] <= N + 1) {
        maxProfit = max(maxProfit, P[day] + solve(day + T[day]));
    }

    return dp[day] = maxProfit;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    T.resize(N + 1);
    P.resize(N + 1);
    memset(dp, -1, sizeof(dp)); 

    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    cout << solve(1) << '\n'; 
    return 0;
}
