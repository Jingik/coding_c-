#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Pos {
    int x, y;
};

const int INF = 1e9;
int N, M, min_distance = INF;
vector<Pos> houses, chickens, selected;

int CalculateDistance() {
    int total_distance = 0;
    for (const auto& house : houses) {
        int house_distance = INF;
        for (const auto& chicken : selected) {
            house_distance = min(house_distance, abs(house.x - chicken.x) + abs(house.y - chicken.y));
        }
        total_distance += house_distance;
    }
    return total_distance;
}

void SelectChickenStores(int idx, int count) {
    if (count == M) {
        min_distance = min(min_distance, CalculateDistance());
        return;
    }

    for (int i = idx; i < chickens.size(); i++) {
        selected.push_back(chickens[i]);
        SelectChickenStores(i + 1, count + 1);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            cin >> val;
            if (val == 1) houses.push_back({i, j});
            else if (val == 2) chickens.push_back({i, j});
        }
    }

    SelectChickenStores(0, 0);
    cout << min_distance << '\n';
    return 0;
}
