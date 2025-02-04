#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> floid(N);
    for (int i = 0; i < N; i++) {
        cin >> floid[i];
    }

    int ft = 0, se = N - 1;
    long long total = floid[ft] + floid[se];
    int total_ft = ft, total_se = se;

    while (ft < se) {
        long long current = floid[ft] + floid[se];

        if (abs(current) < abs(total)) {
            total = current;
            total_ft = ft;
            total_se = se;
        }

        if (current < 0) {
            ft++; 
        }
        else {
            se--; 
        }
    }

    cout << floid[total_ft] << " " << floid[total_se] << "\n";
    return 0;
}
