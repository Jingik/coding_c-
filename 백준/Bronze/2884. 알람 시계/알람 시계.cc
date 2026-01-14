#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int H, M;
    cin >> H >> M;

    int total = H * 60 + M; 
    total -= 45;     

    if (total < 0) {
        total += 24 * 60;   
    }

    H = total / 60;    
    M = total % 60;     

    cout << H << " " << M << endl;
    return 0;
}
