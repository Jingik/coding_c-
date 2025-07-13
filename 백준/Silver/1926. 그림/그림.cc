#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int n, m;
const int MAX = 501;
int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { 0, };
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
queue<pair<int,int>> q;         
vector<int> v;                   
int s = 1;                      

void BFS(int y, int x) {
    visited[y][x] = true;
    q.push(make_pair(y, x));
 
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
                visited[ny][nx] = true;
                s++;
                q.push(make_pair(ny, nx));
            }
        }
    }
}
 
bool compare(int i, int j) {
    return i > j;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
 
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                BFS(i, j);
                v.push_back(s);
                cnt++;
                s = 1;
            }
        }
    }
 
    sort(v.begin(), v.end(), compare);
 
    cout << cnt << endl;
 
    if (cnt == 0) {
        cout << 0 << endl;
    }
    else {
        cout << v[0] << endl;
    }
 
}