#include <string>
#include <vector>

using namespace std;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dir[] = {'d', 'l', 'r', 'u'};
string result = "";
int N, M, R, C, K;
bool found = false;

void dfs(int x, int y, int cnt, string path){
    if (found) return;

    int manhattan = abs(x - R) + abs(y- C);
    if(cnt == K && x == R && y == C){
        result = path;
        found = true;
        return;
    }
    if (cnt >= K || manhattan > K - cnt || (K - cnt - manhattan) % 2 != 0) return;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx > 0 && nx <= N && ny > 0 && ny <= M){
            dfs(nx, ny, cnt + 1, path + dir[i]);
        }
    }

}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N = n; M = m; R = r; C = c; K = k;
    int manhattan = abs(x - r) + abs(y - c);
    if (manhattan > k || (k - manhattan) % 2 != 0) return "impossible";
    
    dfs(x, y, 0, "");
    return result.empty() ? "impossible" : result;
}