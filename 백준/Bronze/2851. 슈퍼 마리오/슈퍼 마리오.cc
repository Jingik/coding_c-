#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int sum = 0;
    int best = 0;

    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        sum += x;

        if (abs(100 - sum) < abs(100 - best)) {
            best = sum;
        }
        
        else if (abs(100 - sum) == abs(100 - best)) {
            if (sum > best) {
                best = sum;
            }
        }
    }

    cout << best << endl;
    return 0;
}
