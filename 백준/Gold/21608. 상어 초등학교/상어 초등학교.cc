#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<vector<int>> classroom;
vector<vector<int>> liked(401); // 학생 번호는 최대 400
vector<int> order;

int score_table[5] = { 0, 1, 10, 100, 1000 };

// 인접한 좋아하는 친구 수, 빈 칸 수 계산
pair<int, int> check(int y, int x, int student) {
    int like_cnt = 0;
    int empty_cnt = 0;
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (classroom[ny][nx] == 0) empty_cnt++;
        else {
            for (int k = 0; k < 4; k++) {
                if (classroom[ny][nx] == liked[student][k]) {
                    like_cnt++;
                    break;
                }
            }
        }
    }
    return make_pair(like_cnt, empty_cnt);
}

void assign(int student) {
    int max_like = -1, max_empty = -1;
    int res_y = 0, res_x = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (classroom[i][j] != 0) continue;

            pair<int, int> result = check(i, j, student);
            int like_cnt = result.first;
            int empty_cnt = result.second;

            if (like_cnt > max_like ||
                (like_cnt == max_like && empty_cnt > max_empty) ||
                (like_cnt == max_like && empty_cnt == max_empty && i < res_y) ||
                (like_cnt == max_like && empty_cnt == max_empty && i == res_y && j < res_x)) {
                max_like = like_cnt;
                max_empty = empty_cnt;
                res_y = i;
                res_x = j;
            }
        }
    }

    classroom[res_y][res_x] = student;
}

int calc_score() {
    int total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int student = classroom[i][j];
            int cnt = 0;
            for (int dir = 0; dir < 4; dir++) {
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                for (int k = 0; k < 4; k++) {
                    if (classroom[ny][nx] == liked[student][k]) {
                        cnt++;
                        break;
                    }
                }
            }
            total += score_table[cnt];
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    classroom.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N * N; i++) {
        int student;
        cin >> student;
        order.push_back(student);
        for (int j = 0; j < 4; j++) {
            int like;
            cin >> like;
            liked[student].push_back(like);
        }
    }

    for (int i = 0; i < order.size(); i++) {
        assign(order[i]);
    }

    cout << calc_score() << '\n';
    return 0;
}
