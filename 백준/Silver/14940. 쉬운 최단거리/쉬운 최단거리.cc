#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int N, M;
int Map[1001][1001] = {0};
int visited[1001][1001] = {0};
int tarx, tary;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void bfs(int stx, int sty)
{
    queue<pair<int, int>> q;
    q.push({stx, sty});
    visited[stx][sty] = 1;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int curx = cx + dx[i];
            int cury = cy + dy[i];

            if (curx >= 0 && curx < N && cury >= 0 && cury < M)
            {
                if (visited[curx][cury] == 0 && Map[curx][cury] != 0)
                {
                    visited[curx][cury] = visited[cx][cy] + 1;
                    q.push({curx, cury});
                }
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            if (a == 2)
            {
                tarx = i;
                tary = j;
            }
            Map[i][j] = a;
        }
    }

    bfs(tarx, tary);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Map[i][j] == 0)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << visited[i][j] - 1 << " ";
            }
        }
        cout << "\n";
    }
}