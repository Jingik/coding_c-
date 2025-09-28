#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, result;
    char game;
    cin >> n >> game;
    unordered_map<string, int> player_list;
    int check_sum = 0;
    string player;
    for (int i = 0; i < n; i++) {
        cin >> player;
        if (player_list[player] > 0) continue;
        player_list[player]++;
        check_sum++;
    }

    if (game == 'Y') {
        result = check_sum;
    }
    else if (game == 'F') {
        result = check_sum / 2;
    }
    else {
        result = check_sum / 3;
    }

    cout << result << '\n';

    return 0;
}
