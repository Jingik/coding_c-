#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int R, C;
vector<string> board;
bool alpha[26];  // 알파벳 방문 여부
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int answer = 0;

void DFS(int x, int y, int depth) {
    answer = max(answer, depth);

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

        char nextChar = board[nx][ny];
        if (!alpha[nextChar - 'A']) {
            alpha[nextChar - 'A'] = true;
            DFS(nx, ny, depth + 1);
            alpha[nextChar - 'A'] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> C;
    board.resize(R);

    for (int i = 0; i < R; ++i) {
        cin >> board[i];
    }

    alpha[board[0][0] - 'A'] = true; 
    DFS(0, 0, 1);

    cout << answer << '\n';
    return 0;
}
