#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int result = 0;
        int b_ptr = 0; 

        for (int i = 0; i < n; i++) {
            while (b_ptr < m && a[i] > b[b_ptr]) {
                b_ptr++;
            }
            result += b_ptr;
        }
        cout << result << '\n';
    }
    return 0;
}