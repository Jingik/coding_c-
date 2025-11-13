#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    long long dp[91];
    
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    
    return 0;
}