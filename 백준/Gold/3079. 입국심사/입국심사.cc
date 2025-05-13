#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N, M;
vector<ll> times;

bool isPossible(ll mid) {
    ll cur = 0;
    for (auto time : times) {
        cur += mid / time;
        if (cur >= M) return true;
    }
    return cur >= M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    times.resize(N);
    
    for (ll i = 0; i < N; i++) {
        cin >> times[i];
    }

    ll left = 1;
    ll right = *max_element(times.begin(), times.end()) * M;
    ll total = right;

    while (left <= right) {
        ll mid = (left + right) / 2;

        if (isPossible(mid)) {
            total = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << total << '\n';

    return 0;
}