#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    long long ans = LLONG_MAX;

    for (int mask = 1; mask < (1 << N); mask++) {
        long long sour = 1;
        long long bitter = 0; 

        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                sour *= v[i].first;
                bitter += v[i].second;
            }
        }

        ans = min(ans, llabs(sour - bitter));
    }

    cout << ans << '\n';
    return 0;
}
