#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> susi_list(N);
    vector<int> count(d + 1, 0); 
    int current_unique = 0;

    for (int i = 0; i < N; i++) {
        cin >> susi_list[i];
    }
    for (int i = 0; i < k; i++) {
        if (count[susi_list[i]] == 0) current_unique++;
        count[susi_list[i]]++;
    }

    int result = current_unique + (count[c] == 0);

    for (int i = 0; i < N; i++) {
        int remove_idx = i; 
        int add_idx = (i + k) % N; 

        count[susi_list[remove_idx]]--;
        if (count[susi_list[remove_idx]] == 0) current_unique--;

        if (count[susi_list[add_idx]] == 0) current_unique++; 
        count[susi_list[add_idx]]++;

        result = max(result, current_unique + (count[c] == 0));
    }

    cout << result << '\n';
    return 0;
}
