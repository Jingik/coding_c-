#include <iostream>
#include <vector>

using namespace std;

struct fireball {
    int x, y;
    int m;
    int d;
    int s;
};

vector<fireball> map[51][51];
vector<fireball> fireballs;

int N, M, K;
int r, c, m, d, s;
int ans = 0;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void move() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j].clear();
        }
    }

    for (int i = 0; i < fireballs.size(); i++) {
        fireball fb = fireballs[i];
        int cm = fb.m, cd = fb.d, cs = fb.s;
        int nx = fb.x, ny = fb.y;
        int cx = fb.x, cy = fb.y;

        for (int j = 0; j < cs; j++) {
            nx += dx[cd];
            ny += dy[cd];
            if (nx < 1) {
                nx = N;
            }
            if (ny < 1) {
                ny = N;
            }
            if (nx > N) {
                nx = 1;
            }
            if (ny > N) {
                ny = 1;
            }
        }

        map[nx][ny].push_back({ nx, ny, cm, cd, cs });
    }
}

void split() {
    vector<fireball> temp;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int msum = 0, ssum = 0;
            bool evenFlag = false, oddFlag = false;

            if (map[i][j].size() == 1) {
                temp.push_back(map[i][j][0]);
            }
            else if (map[i][j].size() >= 2) {
                for (int k = 0; k < map[i][j].size(); k++) {
                    msum += map[i][j][k].m;
                    ssum += map[i][j][k].s;

                    if (map[i][j][k].d % 2 == 0) {
                        evenFlag = true;
                    }
                    else {
                        oddFlag = true;
                    }
                }

                msum /= 5;
                ssum = ssum / map[i][j].size();

                if (msum == 0) {
                    continue;
                }

                if ((evenFlag && !oddFlag) || (!evenFlag && oddFlag)) {
                    temp.push_back({ i, j, msum, 0, ssum });
                    temp.push_back({ i, j, msum, 2, ssum });
                    temp.push_back({ i, j, msum, 4, ssum });
                    temp.push_back({ i, j, msum, 6, ssum });
                }
                else {
                    temp.push_back({ i, j, msum, 1, ssum });
                    temp.push_back({ i, j, msum, 3, ssum });
                    temp.push_back({ i, j, msum, 5, ssum });
                    temp.push_back({ i, j, msum, 7, ssum });
                }
            }
        }
    }
    fireballs = temp;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> m >> s >> d;
        fireballs.push_back({ r, c, m, d, s });
    }

    for (int j = 0; j < K; j++) {
        move();
        split();
    }

    for (int i = 0; i < fireballs.size(); i++) {
        ans += fireballs[i].m;
    }

    cout << ans << '\n';

    return 0;
}