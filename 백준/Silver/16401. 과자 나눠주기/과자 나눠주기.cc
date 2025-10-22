#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int m, n, input;
    cin >> m >> n;

    vector<int> snacks(n);

    for(int i = 0; i < n; i++){
        cin >> snacks[i];
    }

    sort(snacks.begin(), snacks.end());

    int low = 1;
    int high = snacks[n-1];
    int result = 0;

    while(low <= high){
        int mid = (low + high) / 2;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += snacks[i] / mid;    
        }

        if(cnt < m){
            high = mid - 1;
        }
        else{
            result = mid;
            low = mid + 1;
        }
    }

    cout << result;

    return 0;
}