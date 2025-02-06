#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
constexpr int N = 10'000;
int a[2*N + 1];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a[num + N]++;
    }
    
    ll ans = 0;
    for (int i = 0; i < 2*N + 1; i++) {
        if (a[i] == 0) continue;
        int n_abs = -(i - N);
        if (n_abs > 0) {
            for (int j = n_abs>>1; j >= 0; j--) {
                if (n_abs % 2 == 0 && j == n_abs>>1) {
                    ans += (ll)a[i] * (a[j + N] * (a[j + N] - 1))>>1;
                } else {
                    ans += (ll)a[i] * a[j + N] * a[n_abs - j + N];
                }
            }
        } else if (n_abs < 0) {
            for (int j = n_abs/2; j <= -1; j++) {
                if ((i - N) % 2 == 0 && j == n_abs>>1) {
                    ans += (ll)a[i] * (a[j + N] * (a[j + N] - 1))>>1;
                } else {
                    ans += (ll)a[i] * a[j + N] * a[n_abs - j + N];
                }
            }
        } else {
            if (a[i] >= 3) {
                ans += ((ll)a[i] * (a[i] - 1) * (a[i] - 2)) / 6;
            }
        }
    }
   
    cout << ans;
}