#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

int dx[] = { 0, 1, 0, -1 };  
int dy[] = { 1, 0, -1, 0 };

int N, K, L;
int Map[101][101];  // 0: 빈칸, 1: 뱀, 2: 사과
vector<pair<int, char>> order;

int simulate() {
    deque<pair<int, int>> snake; 
    int time = 0, dir = 0;
    snake.push_back({ 1, 1 });
    Map[1][1] = 1;

    int orderIdx = 0;
    while (true) {
        time++;

        // 뱀의 머리를 다음 위치로 이동
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];

        // 벽 또는 자기 자신과 충돌 시 게임 종료
        if (nx < 1 || ny < 1 || nx > N || ny > N || Map[nx][ny] == 1) {
            break;
        }

        // 머리를 이동
        snake.push_front({ nx, ny });

        // 사과가 없으면 꼬리 제거
        if (Map[nx][ny] != 2) {
            int tx = snake.back().first;
            int ty = snake.back().second;
            snake.pop_back();
            Map[tx][ty] = 0;
        }

        Map[nx][ny] = 1;

        if (orderIdx < L && time == order[orderIdx].first) {
            if (order[orderIdx].second == 'D') {
                dir = (dir + 1) % 4;
            }
            else {
                dir = (dir + 3) % 4;
            }
            orderIdx++;
        }
    }

    return time;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        Map[x][y] = 2;
    }

    cin >> L;
    for (int i = 0; i < L; i++) {
        int X;
        char C;
        cin >> X >> C;
        order.push_back({ X, C });
    }

    cout << simulate() << '\n';

    return 0;
}
