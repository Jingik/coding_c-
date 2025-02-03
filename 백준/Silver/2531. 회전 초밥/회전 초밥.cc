#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> susi(n);
    for (int i = 0; i < n; i++) {
        cin >> susi[i];
    }

    vector<int> sushi_count(d + 1, 0);
    int unique_count = 0;

    for (int i = 0; i < k; i++) {
        if (sushi_count[susi[i]] == 0) unique_count++;
        sushi_count[susi[i]]++;
    }

    int max_types = unique_count;

    for (int i = 0; i < n; i++) {
        int remove_idx = i;  
        int add_idx = (i + k) % n; 

        sushi_count[susi[remove_idx]]--;
        if (sushi_count[susi[remove_idx]] == 0) unique_count--;

        if (sushi_count[susi[add_idx]] == 0) unique_count++;
        sushi_count[susi[add_idx]]++;

        if (sushi_count[c] == 0) {
            max_types = max(max_types, unique_count + 1);
        } else {
            max_types = max(max_types, unique_count);
        }
    }

    cout << max_types << "\n";
    return 0;
}
