#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    deque<int> durability(2 * N);
    deque<bool> robots(2 * N, false); 

    for (int i = 0; i < 2 * N; ++i) {
        cin >> durability[i];
    }

    int step = 0;
    int zero_count = 0;

    while (true) {
        step++;

        durability.push_front(durability.back());
        durability.pop_back();
        robots.push_front(robots.back());
        robots.pop_back();
        robots[N - 1] = false;

        for (int i = N - 2; i >= 0; --i) {
            if (robots[i] && !robots[i + 1] && durability[i + 1] > 0) {
                robots[i] = false;
                robots[i + 1] = true;
                durability[i + 1]--;
                if (durability[i + 1] == 0) zero_count++;
            }
        }

        robots[N - 1] = false;

        if (!robots[0] && durability[0] > 0) {
            robots[0] = true;
            durability[0]--;
            if (durability[0] == 0) zero_count++;
        }

        if (zero_count >= K) break;
    }

    cout << step << '\n';
    return 0;
}
