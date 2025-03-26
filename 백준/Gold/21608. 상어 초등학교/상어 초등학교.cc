#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> room(N, vector<int>(N, 0));
    map<int, vector<int>> like; 
    vector<int> order(N * N);     

    for (int i = 0; i < N * N; i++) {
        int num, a, b, c, d;
        cin >> num >> a >> b >> c >> d;
        order[i] = num;
        like[num] = { a, b, c, d };
    }

    for (int idx = 0; idx < order.size(); idx++) {
        int student = order[idx];
        vector<tuple<int, int, int, int>> candidates;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (room[i][j] != 0) continue;

                int like_cnt = 0, empty_cnt = 0;

                for (int dir = 0; dir < 4; dir++) {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];

                    if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;

                    if (room[ni][nj] == 0) empty_cnt++;
                    else {
                        vector<int>& likes = like[student];
                        if (find(likes.begin(), likes.end(), room[ni][nj]) != likes.end()) {
                            like_cnt++;
                        }
                    }
                }

                candidates.push_back(make_tuple(-like_cnt, -empty_cnt, i, j));
            }
        }

        sort(candidates.begin(), candidates.end());
        int x = get<2>(candidates[0]);
        int y = get<3>(candidates[0]);
        room[x][y] = student;
    }

    map<int, int> score_map = { {0, 0}, {1, 1}, {2, 10}, {3, 100}, {4, 1000} };
    int total_score = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cur = room[i][j];
            int cnt = 0;

            for (int dir = 0; dir < 4; dir++) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];

                if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;

                vector<int>& likes = like[cur];
                if (find(likes.begin(), likes.end(), room[ni][nj]) != likes.end()) {
                    cnt++;
                }
            }

            total_score += score_map[cnt];
        }
    }

    cout << total_score << '\n';
    return 0;
}
