#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long T, n, m;
    cin >> T >> n;

    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    cin >> m;
    vector<long long> B(m);
    for (int i = 0; i < m; i++) cin >> B[i];


    unordered_map<long long, long long> sumA;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += A[j];
            sumA[sum]++;
        }
    }

    long long result = 0;
    for (int i = 0; i < m; i++) {
        long long sum = 0;
        for (int j = i; j < m; j++) {
            sum += B[j];
            if (sumA.count(T - sum)) {
                result += sumA[T - sum]; 
            }
        }
    }

    cout << result << '\n';
    return 0;
}
