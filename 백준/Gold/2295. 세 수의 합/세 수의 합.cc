#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> list(N);
    for (int i = 0; i < N; i++) {
        cin >> list[i];
    }

    sort(list.begin(), list.end());

    vector<int> sumList;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sumList.push_back(list[i] + list[j]);
        }
    }

    sort(sumList.begin(), sumList.end());

    for (int k = N - 1; k >= 0; k--) {
        for (int z = 0; z < N; z++) {
            int target = list[k] - list[z];
            if (binary_search(sumList.begin(), sumList.end(), target)) {
                cout << list[k] << endl;
                return 0;
            }
        }
    }

    return 0;
}
