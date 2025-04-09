#include <iostream>

using namespace std;

int N, K;
int durability[201];
bool robots[201];

void rotate() {
    int last_durability = durability[2 * N - 1];
    for (int i = 2 * N - 1; i > 0; --i) {
        durability[i] = durability[i - 1];
        robots[i] = robots[i - 1];
    }
    durability[0] = last_durability;
    robots[0] = false;
    robots[N - 1] = false; 
}

void move_robot() {
    for (int i = N - 1; i > 0; --i) {
        if (robots[i] && !robots[i + 1] && durability[i + 1] > 0) {
            robots[i] = false;
            robots[i + 1] = true;
            durability[i + 1]--;
            if (durability[i + 1] == 0) K--;
        }
    }

    robots[N - 1] = false;

    if (!robots[0] && durability[0] > 0) {
        robots[0] = true;
        durability[0]--;
        if (durability[0] == 0) K--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < 2 * N; ++i) {
        cin >> durability[i];
    }

    int step = 0;

    while (K > 0) {
        step++;
        rotate();  
        move_robot();  
    }

    cout << step << '\n';
    return 0;
}
