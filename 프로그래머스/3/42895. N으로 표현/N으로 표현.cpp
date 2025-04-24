#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;

    vector<set<int>> dp(9);
    
    for (int i = 1; i < 9; i++) {
        int concat = 0;
        for (int k = 0; k < i; k++) {
            concat = concat * 10 + N;
        }
        dp[i].insert(concat);
        for (int j = 1; j < i; j++) {
            for (int x : dp[j]) {
                for (int y : dp[i - j]) {
                    dp[i].insert(x + y);
                    dp[i].insert(x - y);
                    dp[i].insert(x * y);
                    if (y != 0) dp[i].insert(x / y);
                }
            }
        }
        if (dp[i].count(number)) return i;
    }

    return -1;
}
