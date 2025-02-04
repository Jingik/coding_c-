#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canInstall(vector<int>& houses, int C, int distance) {
    int count = 1; 
    int lastInstalled = houses[0];  

    for (int i = 1; i < houses.size(); i++) {
        if (houses[i] - lastInstalled >= distance) {
            count++;  
            lastInstalled = houses[i];
        }
    }
    return count >= C; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, C;
    cin >> N >> C;

    vector<int> houses(N);
    for (int i = 0; i < N; i++) {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());  

    int left = 1; 
    int right = houses[N - 1] - houses[0]; 
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canInstall(houses, C, mid)) {
            result = mid; 
            left = mid + 1; 
        }
        else {
            right = mid - 1; 
        }
    }

    cout << result << endl;
    return 0;
}
