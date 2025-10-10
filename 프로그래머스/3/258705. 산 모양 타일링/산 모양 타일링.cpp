
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    const int MOD = 10007;
    int prev_uncovered = 1; 
    int prev_covered = 0;
    for (int i = 0; i < n; ++i) {
        int next_covered = (prev_uncovered + prev_covered) % MOD;
        int next_uncovered;
        if (tops[i] == 0) {
            next_uncovered = (2LL * prev_uncovered + prev_covered) % MOD;
        } else {
            next_uncovered = (3LL * prev_uncovered + 2LL * prev_covered) % MOD;
        }
        prev_uncovered = next_uncovered;
        prev_covered = next_covered;
    }
    return (prev_uncovered + prev_covered) % MOD;
}