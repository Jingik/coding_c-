#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct mem {
    int num;
    long long g, w, d;
};

bool compare(mem A, mem B) {
    if (A.g != B.g) {
        return A.g > B.g;
    }
    if (A.w != B.w) {
        return A.w > B.w;
    }
    return A.d > B.d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<mem> member(n);

    for (int i = 0; i < n; i++) {
        cin >> member[i].num >> member[i].g >> member[i].w >> member[i].d;
    }

    sort(member.begin(), member.end(), compare);

    int rank = 1;
    if (member[0].num == k) {
        cout << rank << '\n';
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (member[i].g == member[i - 1].g && member[i].w == member[i - 1].w && member[i].d == member[i - 1].d) {
            if (member[i].num == k) {
                cout << rank << '\n';
                return 0;
            }
        }
        else {
            rank = i + 1;
        }

        if (member[i].num == k) {
            cout << rank << '\n';
            return 0;
        }
    }

    return 0;
}
