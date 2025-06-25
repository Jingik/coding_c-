#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

int n, m, v[300005], ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    sort(v, v+m);

    int l = 1, r = v[m - 1];
    while (l<=r) {
        int mid = (l + r) / 2;
        
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += v[i] / mid;
            if (v[i] % mid != 0) cnt++;
        }

        if (cnt <= n) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;

}