#include <iostream>

using namespace std;

int N, K;
int durability[201];
bool robots[201];

void rotate() {
    int last_durability = durability[2 * N - 1];
    bool last_robot = robots[2 * N - 1];

    for (int i = 2 * N - 1; i > 0; --i) {
        durability[i] = durability[i - 1];
        robots[i] = robots[i - 1];
    }
    durability[0] = last_durability;
    robots[0] = false;

    robots[N - 1] = false;
}


int move_robot() {
    int zero_count_in_this_round = 0;
    for (int i = N - 2; i >= 0; --i) {
        if (robots[i] && !robots[i + 1] && durability[i + 1] > 0) {
            robots[i] = false;
            robots[i + 1] = true;
            durability[i + 1]--;
            if (durability[i + 1] == 0) zero_count_in_this_round++;
        }
    }

    robots[N - 1] = false;

    if (!robots[0] && durability[0] > 0) {
        robots[0] = true;
        durability[0]--;
        if (durability[0] == 0) zero_count_in_this_round++;
    }

    return zero_count_in_this_round;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < 2 * N; ++i) {
        cin >> durability[i];
    }

    int step = 0;
    int zero_count = 0;

    while (zero_count < K) {
        step++;
        rotate();
        zero_count += move_robot();
    }

    cout << step << '\n';
    return 0;
}
