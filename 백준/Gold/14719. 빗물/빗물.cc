#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 510;  
int H, W;
int Height[MAX];   
int LeftMax[MAX];   
int RightMax[MAX];   

void Input() {
    cin >> H >> W;
    for (int i = 0; i < W; i++) {
        cin >> Height[i];
    }
}

void Solution() {

    LeftMax[0] = Height[0];
    for (int i = 1; i < W; i++) {
        LeftMax[i] = max(LeftMax[i - 1], Height[i]);
    }

    RightMax[W - 1] = Height[W - 1];
    for (int i = W - 2; i >= 0; i--) {
        RightMax[i] = max(RightMax[i + 1], Height[i]);
    }

    int Answer = 0;
    for (int i = 0; i < W; i++) {
        int WaterHeight = min(LeftMax[i], RightMax[i]) - Height[i];
        if (WaterHeight > 0) {
            Answer += WaterHeight;
        }
    }

    cout << Answer << '\n';
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}
